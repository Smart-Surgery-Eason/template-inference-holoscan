add_executable(dentistry_test
        recorder.hpp
        config.hpp
        utils.hpp
)


target_include_directories(dentistry_test
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(dentistry_test
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        holoscan::core
        holoscan::ops::format_converter
        holoscan::ops::holoviz
        holoscan::ops::inference
        holoscan::ops::segmentation_postprocessor
        holoscan::ops::video_stream_replayer
        holoscan::ops::video_stream_recorder
        ${OpenCV_LIBS}
        dentistry_util
        dentistry_ops
)

include(GoogleTest)

add_test(NAME DentistryTest COMMAND dentistry_test WORKING_DIRECTORY ${CMAKE_BINARY_DIR})