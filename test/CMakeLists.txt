cmake_minimum_required(VERSION 3.2)
project(md5_tests)

add_subdirectory(lib/googletest)

include_directories(${MD5_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/md5_tests.cpp)

add_executable(md5_tests ${SOURCE_FILES})
target_link_libraries(md5_tests md5 gtest)
install(TARGETS md5_tests DESTINATION bin)

