cmake_minimum_required(VERSION 3.16)
project(cpp_cache_LiamCoopR)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

include_directories(include/ra)

add_executable(test_matrix_transpose app/test_matrix_transpose.cpp include/ra/matrix_transpose.hpp)
add_executable(test_matrix_multiply app/test_matrix_multiply.cpp include/ra/matrix_multiply.hpp)

set(Boost_USE_MULTITHREADED FALSE)
find_package(Boost 1.72.0 COMPONENTS)
if(Boost_FOUND)
    include_directories(${Boost_LIBRARIES})
    add_executable(test_fft app/test_fft.cpp include/ra/fft.hpp)
    #target_link_libraries(test_fft PUBLIC include/ra/fft.hpp)
endif()
