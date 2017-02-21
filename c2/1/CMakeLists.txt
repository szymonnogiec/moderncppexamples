cmake_minimum_required(VERSION 3.6)
project(1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SoundexTest.cpp CharUtil.h StringUtil.h)
add_executable(1 ${SOURCE_FILES})

include_directories("/usr/include")
link_directories("/usr/lib")

enable_testing()

# gmock needs pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(1 Threads::Threads)
target_link_libraries(1 gmock)
target_link_libraries(1 gmock_main)

add_executable(RunSoundexTest SoundexTest.cpp)
target_link_libraries(RunSoundexTest Threads::Threads)
target_link_libraries(RunSoundexTest gmock gmock_main)
add_test(RunSoundexTest RunSoundexTest)
