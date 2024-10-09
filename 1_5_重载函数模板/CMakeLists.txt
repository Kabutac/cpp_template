cmake_minimum_required(VERSION 3.12)
project(test LANGUAGES CXX)

# 将当前目录下的所有.cpp文件添加到变量SOURCES中
file(GLOB SOURCES "*.cpp")

# 然后使用add_executable或add_library命令添加这些源文件
add_executable(a.out ${SOURCES})
