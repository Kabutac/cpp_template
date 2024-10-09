#include <iostream>
#include <string>
#include <assert.h>

void undeclared(){
    std::cout << "调用undeclared()" << std::endl;
}

template<typename T>
void undeclared(T t){
    std::cout << "调用undeclared(T)" << std::endl;
}

template<typename T>
void foo(T t)
{
    undeclared(); // 若undeclared()未知，则在第一阶段编译时报错
    undeclared(t); // 若undeclared(T)未知，则在第二阶段编译时报错
    undeclared<int>(t); // 若undeclared(T)未知，则在第二阶段编译时报错
}

int main()
{
    foo(3);
}


