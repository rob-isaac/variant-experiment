cmake_minimum_required(VERSION 3.9)
enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_library(variant_experiment_obj SHARED src/VariantSlow.cpp)
target_include_directories(variant_experiment_obj PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_options(variant_experiment_obj PRIVATE -g -O2 -Wall -Wextra -pedantic -Werror)

add_subdirectory(bench)
