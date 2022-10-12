add_executable(bench bench.cpp)

target_include_directories(bench PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(benchmark REQUIRED)

target_compile_options(bench PRIVATE -g -O2 -Wall -Wextra -pedantic -Werror)
target_link_libraries(bench PRIVATE benchmark::benchmark)
target_link_libraries(bench PRIVATE variant_experiment_obj)
