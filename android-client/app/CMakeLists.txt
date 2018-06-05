cmake_minimum_required(VERSION 3.4.1)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CPP_LOCAL_PATH ${CMAKE_SOURCE_DIR}/src/main/cpp)
set(PNG_LOCAL_PATH ${CPP_LOCAL_PATH}/libpng)

add_library( libpng STATIC
             ${PNG_LOCAL_PATH}/png.c
             ${PNG_LOCAL_PATH}/pngerror.c
             ${PNG_LOCAL_PATH}/pngget.c
             ${PNG_LOCAL_PATH}/pngmem.c
             ${PNG_LOCAL_PATH}/pngpread.c
             ${PNG_LOCAL_PATH}/pngread.c
             ${PNG_LOCAL_PATH}/pngrio.c
             ${PNG_LOCAL_PATH}/pngrtran.c
             ${PNG_LOCAL_PATH}/pngrutil.c
             ${PNG_LOCAL_PATH}/pngset.c
             ${PNG_LOCAL_PATH}/pngtrans.c
             ${PNG_LOCAL_PATH}/pngwio.c
             ${PNG_LOCAL_PATH}/pngwrite.c
             ${PNG_LOCAL_PATH}/pngwtran.c
             ${PNG_LOCAL_PATH}/pngwutil.c
             )

find_library( z-lib z )

target_link_libraries(libpng ${z-lib})

add_library( game SHARED
             ${CPP_LOCAL_PATH}/platform_asset_utils.cpp
             ${CPP_LOCAL_PATH}/platform_log.cpp
             ${CPP_LOCAL_PATH}/asset_utils.cpp
             ${CPP_LOCAL_PATH}/buffer.cpp
             ${CPP_LOCAL_PATH}/program.cpp
             ${CPP_LOCAL_PATH}/game.cpp
             ${CPP_LOCAL_PATH}/image.cpp
             ${CPP_LOCAL_PATH}/shader.cpp
             ${CPP_LOCAL_PATH}/texture.cpp
             ${CPP_LOCAL_PATH}/game_objects.cpp
             )

set( PROTOBUF_SRC /home/views/Загрузки/protobuf-3.5.1/src )
include_directories( ${PROTOBUF_SRC} )

add_library( protobuf SHARED
    ${PROTOBUF_SRC}/google/protobuf/arena.cc
    ${PROTOBUF_SRC}/google/protobuf/arenastring.cc
    ${PROTOBUF_SRC}/google/protobuf/extension_set.cc
    ${PROTOBUF_SRC}/google/protobuf/generated_message_util.cc
    ${PROTOBUF_SRC}/google/protobuf/io/coded_stream.cc
    ${PROTOBUF_SRC}/google/protobuf/io/zero_copy_stream.cc
    ${PROTOBUF_SRC}/google/protobuf/io/zero_copy_stream_impl_lite.cc
    ${PROTOBUF_SRC}/google/protobuf/message_lite.cc
    ${PROTOBUF_SRC}/google/protobuf/repeated_field.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/atomicops_internals_x86_gcc.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/atomicops_internals_x86_msvc.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/bytestream.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/common.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/int128.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/once.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/status.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/statusor.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/stringpiece.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/stringprintf.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/structurally_valid.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/strutil.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/time.cc
    ${PROTOBUF_SRC}/google/protobuf/wire_format_lite.cc
    ${PROTOBUF_SRC}/google/protobuf/any.cc
    ${PROTOBUF_SRC}/google/protobuf/any.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/api.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/importer.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/parser.cc
    ${PROTOBUF_SRC}/google/protobuf/descriptor.cc
    ${PROTOBUF_SRC}/google/protobuf/descriptor.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/descriptor_database.cc
    ${PROTOBUF_SRC}/google/protobuf/duration.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/dynamic_message.cc
    ${PROTOBUF_SRC}/google/protobuf/empty.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/extension_set_heavy.cc
    ${PROTOBUF_SRC}/google/protobuf/field_mask.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/generated_message_reflection.cc
    ${PROTOBUF_SRC}/google/protobuf/io/gzip_stream.cc
    ${PROTOBUF_SRC}/google/protobuf/io/printer.cc
    ${PROTOBUF_SRC}/google/protobuf/io/strtod.cc
    ${PROTOBUF_SRC}/google/protobuf/io/tokenizer.cc
    ${PROTOBUF_SRC}/google/protobuf/io/zero_copy_stream_impl.cc
    ${PROTOBUF_SRC}/google/protobuf/map_field.cc
    ${PROTOBUF_SRC}/google/protobuf/message.cc
    ${PROTOBUF_SRC}/google/protobuf/reflection_ops.cc
    ${PROTOBUF_SRC}/google/protobuf/service.cc
    ${PROTOBUF_SRC}/google/protobuf/source_context.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/struct.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/mathlimits.cc
    ${PROTOBUF_SRC}/google/protobuf/stubs/substitute.cc
    ${PROTOBUF_SRC}/google/protobuf/text_format.cc
    ${PROTOBUF_SRC}/google/protobuf/timestamp.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/type.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/unknown_field_set.cc
    ${PROTOBUF_SRC}/google/protobuf/util/field_comparator.cc
    ${PROTOBUF_SRC}/google/protobuf/util/field_mask_util.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/datapiece.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/default_value_objectwriter.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/error_listener.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/field_mask_utility.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/json_escaping.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/json_objectwriter.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/json_stream_parser.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/object_writer.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/proto_writer.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/protostream_objectsource.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/protostream_objectwriter.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/type_info.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/type_info_test_helper.cc
    ${PROTOBUF_SRC}/google/protobuf/util/internal/utility.cc
    ${PROTOBUF_SRC}/google/protobuf/util/json_util.cc
    ${PROTOBUF_SRC}/google/protobuf/util/message_differencer.cc
    ${PROTOBUF_SRC}/google/protobuf/util/time_util.cc
    ${PROTOBUF_SRC}/google/protobuf/util/type_resolver_util.cc
    ${PROTOBUF_SRC}/google/protobuf/wire_format.cc
    ${PROTOBUF_SRC}/google/protobuf/wrappers.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/code_generator.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/command_line_interface.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_enum.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_enum_field.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_extension.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_field.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_file.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_generator.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_helpers.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_map_field.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_message.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_message_field.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_primitive_field.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_service.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/cpp/cpp_string_field.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/plugin.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/plugin.pb.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/python/python_generator.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/ruby/ruby_generator.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/subprocess.cc
    ${PROTOBUF_SRC}/google/protobuf/compiler/zip_writer.cc
    )

# add_library( protobuf SHARED IMPORTED)
# set_target_properties( protobuf PROPERTIES IMPORTED_LOCATION "/usr/local/protobuf/armeabi-v7a/lib/libprotobuf-lite.so")
# set_target_properties( protobuf PROPERTIES IMPORTED_LOCATION "/usr/local/protobuf/arm64-v8a/lib/libprotobuf-lite.so")

find_library( gles-lib GLESv2 )
find_library( log-lib log )
find_library( android-lib android )
find_library( stdcpp-lib stdc++ )

target_link_libraries( game
                       libpng
                       ${gles-lib}
                       ${log-lib}
                       ${android-lib}
                       protobuf
                     )
