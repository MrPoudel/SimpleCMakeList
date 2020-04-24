#[[This is a simple CMakeLists.txt example.
It shows how to organize a C/C++ project with different source and header directory
]]
cmake_minimum_required (VERSION 3.7)
project (cmake_example)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Find Cppcheck
find_package(Cppcheck)
set(CPPCHECK_XML_OUTPUT "${PROJECT_BINARY_DIR}/analysis/cppcheck/cppcheck_analysis.xml")
find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    list(
        APPEND CMAKE_CXX_CPPCHECK 
            "--enable=warning"
            "--inconclusive"
            "--force" 
            "--inline-suppr"
            #"--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
    )
endif()

#find_package(Sphinx REQUIRED)
find_package(LATEX)

#set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

## Start of checking the upto date uncrustify
find_package(Git REQUIRED) #QUIET --> QUIET option disables messages if the package cannot be found

if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/uncrustify/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(extern/uncrustify)

## Uncrustify checking ends here


#include_directories ("${PROJECT_SOURCE_DIR}/headers") ## This line can be removed with target_include_directories

add_library (mylib sources1/cube.c sources2/square.c)
target_include_directories(mylib  
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/headers"
)

add_executable (main examples/main.c)
target_link_libraries (main mylib)

add_executable (simple_pointer examples/simple_pointer.c)
add_executable (pointer_to_functions1 examples/pointer_to_functions1.c)
add_executable (pointer_to_functions2 examples/pointer_to_functions2.c)
add_executable (pointer_to_functions3 examples/pointer_to_functions3.c)
add_executable (random_test examples/random_test.c)
add_executable (variable_argument_func examples/variable_argument_func.c)
add_executable (unix_c examples/unix_c.c)
add_executable (mem_leak_checking examples/mem_leak_checking.c)
add_executable (command_line_args examples/command_line_args.c)
add_executable (read_number_from_file examples/file_RW/read_number_from_file.c)
file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/examples/file_RW/my_first_file.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable (read_until_end_of_file examples/file_RW/read_until_end_of_file.c)
add_executable (read_until_EOF examples/file_RW/read_until_EOF.c)
file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/examples/file_RW/my_second_file.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable (multithreading examples/multithreading.c)
add_executable (multithreading_advance examples/multithreading_advance.c)
add_executable (fcn_ptr_as_arg examples/fcn_ptr_as_arg.c)
add_executable (return_fcn_ptr examples/return_fcn_ptr.c)
add_executable (array_of_fcn_ptr examples/array_of_fcn_ptr.c)
add_executable (function_ptr_as_struct_member examples/function_ptr_as_struct_member.c)
#add_executable (singlyLinkedList examples/singlyLinkedList.c)
#add_executable (singlyLinkedList2 examples/singlyLinkedList2.c)
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

#add_subdirectory(docs)
#add_subdirectory(test)

##Adding tests
include(CTest)
add_test(test1 "${CMAKE_BINARY_DIR}/simple_pointer") # This is not the real test, it's just a executable used which always passes

message("cmake installation prefix is set to :${CMAKE_INSTALL_PREFIX}")
##Installing some library and headers

set(HEADERS ${PROJECT_SOURCE_DIR}/headers/cube.h ${PROJECT_SOURCE_DIR}/headers/square.h)

install(TARGETS mylib DESTINATION lib)
install(FILES "${PROJECT_SOURCE_DIR}/headers/cube.h" DESTINATION include)
install(FILES "${PROJECT_SOURCE_DIR}/headers/square.h" DESTINATION include)

## Packaging

set(CPACK_GENERATOR "DEB") # without this line .tar.gz will be created..by this .deb
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "DovanTech") #required
include(CPack)
