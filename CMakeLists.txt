cmake_minimum_required(VERSION 3.20)
project(template LANGUAGES CXX CUDA)

# Google Test setup
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Finds the holoscan SDK
find_package(holoscan REQUIRED CONFIG PATHS "/opt/nvidia/holoscan")

#
add_executable(template
        src/application/application.cpp
)

set(CMAKE_CUDA_ARCHITECTURES "70;80;90")

target_link_libraries(template
        PRIVATE
        holoscan::core
        holoscan::ops::format_converter
        holoscan::ops::holoviz
        holoscan::ops::inference
        holoscan::ops::segmentation_postprocessor
        holoscan::ops::video_stream_replayer
        holoscan::ops::video_stream_recorder
)


set_target_properties(template PROPERTIES CUDA_ARCHITECTURES "80;90")

# testing
enable_testing()
add_subdirectory(tests)