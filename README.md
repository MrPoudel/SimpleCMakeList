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

Usuage

##Requirements

1. The GNU toolchain: 
2. cmake
3. GNU make

##Instructions

###Building

1. Clone the repository: https://github.com/MrPoudel/SimpleCMakeList.git 

2. cd SimpleCMakeList

3. mkdir build

4. cd build && cmake ..

5. make



