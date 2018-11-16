#[[This is a simple CMakeLists.txt example.
It shows how to organize a C/C++ project with different source and header directory
]]
cmake_minimum_required (VERSION 3.7)
project (cmake_example)

#set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories ("${PROJECT_SOURCE_DIR}/headers")
add_library (mylib sources1/cube.c sources2/square.c)

add_executable (main examples/main.c)
target_link_libraries (main mylib)

add_executable (pointer_to_functions1 examples/pointer_to_functions1.c)
add_executable (pointer_to_functions2 examples/pointer_to_functions2.c)
add_executable (pointer_to_functions3 examples/pointer_to_functions3.c)
add_executable (random_test examples/random_test.c)
add_executable (variable_argument_func examples/variable_argument_func.c)
add_executable (unix_c examples/unix_c.c)

add_executable (multithreading examples/multithreading.c)
add_executable (multithreading_advance examples/multithreading_advance.c)
#target_link_libraries (thread_demo pthread)
#target_link_libraries (thread_demo Threads::Threads)
target_link_libraries (multithreading ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (multithreading_advance ${CMAKE_THREAD_LIBS_INIT})


#Alternative:1
#[[#target_link_libraries (thread_demo pthread)]]

#Alternative:2
#[[find_package (Threads)
add_executable (myapp main.cpp ...)
target_link_libraries (myapp ${CMAKE_THREAD_LIBS_INIT}]]


#Alternative:2
#[[set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
[[target_link_libraries(my_app Threads::Threads)]]

