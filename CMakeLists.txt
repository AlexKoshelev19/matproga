cmake_minimum_required(VERSION 3.20)
project(SimplexLab1 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(UNICODE _UNICODE)

add_executable(simplex_app
    src/main.cpp
    src/InputReader.cpp
    src/ExcelReporter.cpp
    src/SimplexSolver.cpp
)

target_include_directories(simplex_app PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/external/libxl/include_cpp"
)

target_link_libraries(simplex_app PRIVATE
    "${CMAKE_SOURCE_DIR}/external/libxl/lib64/libxl.lib"
)

target_link_options(simplex_app PRIVATE -static-libgcc -static-libstdc++)

add_custom_command(TARGET simplex_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/external/libxl/bin64/libxl.dll"
    "$<TARGET_FILE_DIR:simplex_app>/libxl.dll"
)

add_custom_command(TARGET simplex_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/input.txt"
    "$<TARGET_FILE_DIR:simplex_app>/input.txt"
)