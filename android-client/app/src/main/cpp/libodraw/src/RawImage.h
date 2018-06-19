#include <GLES2/gl2.h>
#include <string>
#include <cassert>

#include "../libpng/png.h"
#include "../libpng/pngconf.h"

namespace OpenDraw {
    typedef struct {
        const png_byte *data;
        const png_size_t size;
    } DataHandle;

    typedef struct {
        const DataHandle data;
        png_size_t offset;
    } ReadDataHandle;

    typedef struct {
        const png_uint_32 width;
        const png_uint_32 height;
        const int color_type;
    } PngInfo;

    class RawImage {
    public:
        RawImage(const void *data, size_t size);

        ~RawImage();

        int width() const;

        int height() const;

        int size() const;

        GLenum glColorFormat() const;

        const png_byte *getData() const;


    private:

        int width_;
        int height_;
        int size_;
        GLenum glColorFormat_;
        const png_byte *data_;

// Reads in the PNG data, and then it asks libpng to perform several transformations based on the PNG type:
// - Transparency information is converted into a full alpha channel.
// - Grayscale images are converted to 8-bit.
// - Paletted images are converted to full RGB.
// - RGB images get an alpha channel added, if none is present.
// - Color channels are converted to 8-bit, if less than 8-bit or 16-bit.
        PngInfo readAndUpdateInfo(const png_structp png_ptr, const png_infop info_ptr);

// Decode the PNG image data into raw image data
        DataHandle readEntirePNGImage(
                const png_structp png_ptr,
                const png_infop info_ptr,
                const png_uint_32 height);

        GLenum getGLColorFormat(const int pngColorFormat);
    };
}