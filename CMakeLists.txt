cmake_minimum_required(VERSION 2.8)

add_definitions("-std=c++11")
set(CMAKE_BUILD_TYPE Release)

set(src_main main.cpp)

find_package(PkgConfig)
pkg_check_modules(OPENCV REQUIRED opencv)

find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

include_directories(${OPENCV_INCLUDE_DIRS})
link_directories(${OPENCV_LIBRARY_DIRS})

add_executable(ACV
    ${src_main}
)

target_link_libraries(ACV ${OPENCV_LIBRARIES})
