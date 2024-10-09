#include <iostream>
#include <type_traits>


template<typename T>
void print_type(T value) {
    std::cout << "类型推导结果：" << typeid(T).name() << std::endl;
}

template<typename T1, typename T2>
auto max1 (T1 a, T2 b)
{
    return b < a ? a : b;
}

template<typename T1, typename T2>
auto max2 (T1 a, T2 b) -> decltype(b<a?a:b)
{
    return b < a ? a : b;
}

template<typename T1, typename T2>
auto max3 (T1 a, T2 b) -> decltype(b<a?a:b){
    return b < a ? a : b;
}

template<typename T1, typename T2>
auto max4 (T1 a, T2 b) -> decltype(true?a:b){
    return b < a ? a : b;
}

template<typename T1, typename T2>
auto max5 (T1 a, T2 b) -> typename std::decay<decltype(true?a:b)>::type //typename在这里确保编译器正确解析::type为类型名，而不是把整个表达式视为某种其他构造。
{
    return b < a ? a : b;
}

template<typename T1, typename T2>
std::common_type_t<T1,T2> max6 (T1 a, T2 b)
{
    return b < a ? a : b;
}

template<typename T1, typename T2,
typename RT = std::common_type_t<T1,T2>>    //显示指定返回值为long类型
RT max7 (T1 a, T2 b)
{
    return b < a ? a : b;
}

template<typename RT = long, typename T1, typename T2>  //显式指定返回值为long类型
RT max8 (T1 a, T2 b)
{
    return b < a ? a : b;
}

int main() {

    double ia = 1.0, ib = 5;
    float fa = 5.1, fb = 6.2;

    auto res1 = max1(ia, fa);
    print_type(res1);
    auto res2 = max2(ia, fa);
    print_type(res2);
    auto res3 = max3(ia, fa);
    print_type(res3);
    auto res4 = max4(ia, fa);
    print_type(res4);
    auto res5 = max5(ia, fa);
    print_type(res5);
    auto res6 = max6(ia, fa);
    print_type(res6);
    auto res7 = max7(ia, fa);
    print_type(res7);
    auto res8 = max8(ia, fa);
    print_type(res8);
    
    return 0;
}
