cmake_minimum_required(VERSION 3.2)
project(md5app)

add_subdirectory(md5)
include_directories(md5)

add_subdirectory(argparse)
include_directories(argparse/include)

set(SOURCE_FILES main.cpp)

add_executable(md5app ${SOURCE_FILES})
target_link_libraries(md5app md5)
install(TARGETS md5app DESTINATION ${PROJECT_INSTALL_BIN_DIR})
