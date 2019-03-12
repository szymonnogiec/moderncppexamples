cmake_minimum_required(VERSION 3.6)
project(c3_1)

set(CMAKE_CXX_STANDARD 17)

macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main gmock_main pthread)
    add_test(${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(c3_1
        main.cpp
        RetweetCollecionTest.cpp
        )
