# SimpleCMakeList
This project shows how to create and build a very simple cmake project. The purpose of this project is to help people to organize the development of their C/C++ projects. It also includes the structure to create the documentation of the project. 
The directory structure of the Project is as follows:

```
SimpleCMakeList

├── CMakeLists.txt
├── Examples
│   └── main.c
├── headers
│   ├── cube.h
│   └── square.h
├── LICENSE
├── README.md
├── sources1
│   └── cube.c
└── sources2
|   └── square.c
|
|   ├── build
│   
├── cmake
│   ├── FindCheck.cmake
│   ├── FindSphinx.cmake
│   └── FindValgrind.cmake
├── CMakeLists.txt
├── docs
│   ├── _build
│   ├── CMakeLists.txt
│   ├── conf.py.in
│   ├── index.rst
│   ├── make.bat
│   ├── Makefile
│   ├── _static
│   ├── _templates
│   └── test.rst
├── examples
│   ├── main.c
│   ├── multithreading_advance.c
│   ├── multithreading.c
│   ├── pointer_to_functions1.c
│   ├── pointer_to_functions2.c
│   ├── pointer_to_functions3.c
│   ├── random_test.c
│   ├── unix_c.c
│   └── variable_argument_func.c
├── headers
│   ├── cube.h
│   └── square.h
├── LICENSE
├── README.md
├── sources1
│   └── cube.c
└── sources2
    └── square.c

```

After you compile the project the generated HTML document looks like :

![See the doc!](https://github.com/MrPoudel/SimpleCMakeList/tree/master/docs/img/Screenshot_2018-11-16.png)

## Hint for documentation
- Create a directory called docs in project's root directory. Make sure that you have already installed the Sphinx package, then run the command: sphinx-quickstart. Further information can be found here [link](https://eb2.co/blog/2012/03/sphinx-and-cmake-beautiful-documentation-for-c---projects/)

Usuage

# Requirements

- [  x] cmake
- [x] GNU make
- [x] build-essential
- [ ] git
- [x] pkg-config 
- [ ] python

##Instructions

# Building

1. Clone the repository: `https://github.com/MrPoudel/SimpleCMakeList.git` 

2. `cd SimpleCMakeList`

3. `mkdir build`

4. `cd build && cmake ..`

5. `make`

# How to add tests

To integrate the tests in cmake we need `include(CTest)`. After that we can use `add_test()` function to generate the tests.
`add_test( "name of test" "your_executable" option_arg1 optional_arg_2 ...)`

Running the test: `$ ctest`

# How to install the library 

With cmake the library can be installed in the `CMAKE_INSTALL_PREFIX/your_favored_path` directory. In most of the cases, installation means copying the libraries and the header file in bin and include directory. Using `install(FILES "library_name_with_path" DESTINATION include)` and 
`install(TARGETS "library_name_with_path" DESTINATION lib)`.

So, the installation directories will be:
`CMAKE_INSTALL_PREFIX/bin` and `CMAKE_INSTALL_PREFIX/lib`

Installing:
`$ sudo make install`

# How to create packaging

Packaging the library means that it can be packed into compressed files. Additionally, we can also create the installation executable. When this executable is installed, it takes care of the library installationa as done by the `install` command.
`include(CPack)` needs to be added in the CMakeLists.txt file.

Packaging:
`$ cpack` or `$ make package`
After that it will create the `.deb` package which can be installed using `sudo dpkg -i package_name.deb`


