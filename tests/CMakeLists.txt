add_executable(template_test
        recorder.hpp
        config.hpp
        utils.hpp
)


target_include_directories(template_test
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(template_test
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        holoscan::core
)

include(GoogleTest)

add_test(NAME TemplateTests COMMAND template_test WORKING_DIRECTORY ${CMAKE_BINARY_DIR})