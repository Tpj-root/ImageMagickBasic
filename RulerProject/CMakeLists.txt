cmake_minimum_required(VERSION 3.15)

project(RulerProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)

pkg_check_modules(MAGICK REQUIRED Magick++)

add_executable(ruler
    src/main.cpp
    src/ruler.cpp
)

target_include_directories(ruler PRIVATE
    include
    ${MAGICK_INCLUDE_DIRS}
)

target_compile_options(ruler PRIVATE
    ${MAGICK_CFLAGS_OTHER}
)

target_link_directories(ruler PRIVATE
    ${MAGICK_LIBRARY_DIRS}
)

target_link_libraries(ruler PRIVATE
    ${MAGICK_LIBRARIES}
)