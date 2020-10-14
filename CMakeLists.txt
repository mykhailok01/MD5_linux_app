cmake_minimum_required(VERSION 3.2)

project(md5project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(PROJECT_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(PROJECT_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(MD5_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/md5)

include_directories(${PROJECT_INSTALL_INCLUDE_DIR})
include_directories(${MD5_HEADERS_DIR})

add_subdirectory(src)
#add_subdirectory(test)


