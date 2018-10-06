#[[This is a simple CMakeLists.txt example.
It shows how to organize a C/C++ project with different source and header directory
]]
cmake_minimum_required (VERSION 3.7)
project (cmake_example)

include_directories ("${PROJECT_SOURCE_DIR}/headers")
add_library (mylib sources1/cube.c sources2/square.c)

add_executable (Example Examples/main.c)
target_link_libraries (Example mylib)

