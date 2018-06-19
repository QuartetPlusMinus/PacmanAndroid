#include "RawImage.h"

RawImage::RawImage(const void *data, size_t size) {

    // Checks that the PNG data is present and has a valid header.
    assert(data != NULL && size > 8);
    assert(png_check_sig((png_const_bytep) data, 8));

    // This initializes the PNG structures that we’ll use to read in the rest of the data
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    assert(png_ptr != NULL);
    png_infop info_ptr = png_create_info_struct(png_ptr);
    assert(info_ptr != NULL);

    ReadDataHandle png_data_handle = (ReadDataHandle) {{(png_byte *) data, size},
                                                       0};
    png_set_read_fn(png_ptr, &png_data_handle, readPngDataCallback);

    assert(setjmp(png_jmpbuf(png_ptr)) == 0);

    // Use one of our helper functions here to parse the PNG information, such as the color format, and convert the PNG into a format that we want
    const PngInfo png_info = readAndUpdateInfo(png_ptr, info_ptr);
    const DataHandle raw_image = readEntirePNGImage(
            png_ptr, info_ptr, png_info.height);

    // Use another helper function here to read in and decode the PNG image data.
    png_read_end(png_ptr, info_ptr);
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    width_ = (int) png_info.width,
    height_ = (int) png_info.height,
    this->size_ = (int) raw_image.size,
    glColorFormat_ = getGLColorFormat(png_info.color_type),
    this->data_ = raw_image.data;
}

RawImage::~RawImage() {
    delete[] data_;
}

int RawImage::width() const {
    return width_;
}

int RawImage::height() const {
    return height_;
}

int RawImage::size() const {
    return size_;
}

GLenum RawImage::glColorFormat() const {
    return glColorFormat_;
}

const png_byte *RawImage::getData() const {
    return data_;
}

static void RawImage::readPngDataCallback(
        png_structp png_ptr, png_byte *raw_data, png_size_t read_length) {
    ReadDataHandle *handle = (ReadDataHandle *) png_get_io_ptr(png_ptr);
    const png_byte *png_src = handle->data.data + handle->offset;

    memcpy(raw_data, png_src, read_length);
    handle->offset += read_length;
}

PngInfo RawImage::readAndUpdateInfo(const png_structp png_ptr, const png_infop info_ptr) {
    png_uint_32 width, height;
    int bit_depth, color_type;

    png_read_info(png_ptr, info_ptr);
    png_get_IHDR(
            png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, NULL, NULL, NULL);

    // Convert transparency to full alpha
    if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png_ptr);

    // Convert grayscale, if needed.
    if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
        png_set_expand_gray_1_2_4_to_8(png_ptr);

    // Convert paletted images, if needed.
    if (color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png_ptr);

    // Add alpha channel, if there is none.
    // Rationale: GL_RGBA is faster than GL_RGB on many GPUs)
    if (color_type == PNG_COLOR_TYPE_PALETTE || color_type == PNG_COLOR_TYPE_RGB)
        png_set_add_alpha(png_ptr, 0xFF, PNG_FILLER_AFTER);

    // Ensure 8-bit packing
    if (bit_depth < 8)
        png_set_packing(png_ptr);
    else if (bit_depth == 16)
        png_set_scale_16(png_ptr);

    png_read_update_info(png_ptr, info_ptr);

    // Read the new color type after updates have been made.
    color_type = png_get_color_type(png_ptr, info_ptr);

    return (PngInfo) {width, height, color_type};
}

DataHandle RawImage::readEntirePNGImage(
        const png_structp png_ptr,
        const png_infop info_ptr,
        const png_uint_32 height) {
    const png_size_t row_size = png_get_rowbytes(png_ptr, info_ptr);
    const size_t data_length = row_size * height;
    assert(row_size > 0);

    png_byte *raw_image = (png_byte *) malloc(data_length);
    assert(raw_image != NULL);

    png_byte *row_ptrs[height];

    png_uint_32 i;
    for (i = 0; i < height; i++) {
        row_ptrs[i] = raw_image + i * row_size;
    }

    png_read_image(png_ptr, &row_ptrs[0]);

    return (DataHandle) {raw_image, data_length};
}

GLenum RawImage::getGLColorFormat(const int pngColorFormat) {
    assert(pngColorFormat == PNG_COLOR_TYPE_GRAY
           || pngColorFormat == PNG_COLOR_TYPE_RGB_ALPHA
           || pngColorFormat == PNG_COLOR_TYPE_GRAY_ALPHA);

    switch (pngColorFormat) {
        case PNG_COLOR_TYPE_GRAY:
            return GL_LUMINANCE;
        case PNG_COLOR_TYPE_RGB_ALPHA:
            return GL_RGBA;
        case PNG_COLOR_TYPE_GRAY_ALPHA:
            return GL_LUMINANCE_ALPHA;
    }

    return 0;
}