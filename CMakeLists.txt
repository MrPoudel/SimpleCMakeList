#CMake example
cmake_minimum_required(VERSION 3.7)
project(cmake_example)
set(SOURCES 
	sources/main.c
	sources/functions.c
)
add_executable(main ${SOURCES})
target_include_directories(main 
	PUBLIC ${PROJECT_SOURCE_DIR}/headers
) 
