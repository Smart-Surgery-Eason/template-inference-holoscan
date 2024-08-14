add_executable(dentistry_test
        recorder.hpp
        config.hpp
        utils.hpp
)


target_include_directories(dentistry_test
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(dentistry_test
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        holoscan::core
)

include(GoogleTest)

add_test(NAME DentistryTest COMMAND dentistry_test WORKING_DIRECTORY ${CMAKE_BINARY_DIR})