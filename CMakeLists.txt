cmake_minimum_required(VERSION 3.20)

project(SparseNet
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(SparseNet
    SparseNet/cpp/src/main.cpp
)

target_include_directories(SparseNet
    PRIVATE
    SparseNet/cpp/includes
)

if(WIN32)

target_link_libraries(SparseNet 
    PRIVATE 
    ws2_32
)

endif()