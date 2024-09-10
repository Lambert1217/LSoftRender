cmake_minimum_required(VERSION 3.26)

# 本项目使用vcpkg进行包管理，此处设置三元组（须在project()之前）
set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")

project(lsr)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES src/*.cpp)

find_package(SDL2 CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)