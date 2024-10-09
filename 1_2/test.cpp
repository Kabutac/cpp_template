#include <iostream>

template<typename T1, typename T2>
void func1(T1& a, T2& b) {
    std::cout << "类型推导结果：" << typeid(T1).name() << std::endl;
    std::cout << "类型推导结果：" << typeid(T2).name() << std::endl;
}

template<typename T>
void func2(T& a, T& b) {
    std::cout << "类型推导结果：" << typeid(T).name() << std::endl;
}

template<typename T>
void func(T value) {
    std::cout << "类型推导结果：" << typeid(T).name() << std::endl;
}

int main() {

    int i = 10;
    const int ci = 20;
    float f = 0.3;
    float& f1 = f;
    double b = 3.14;

    func(i);       // 输出：类型推导结果：i
    func(ci);      // 输出：类型推导结果：i (同样被推导为int)
    func1(i, ci);  // 输出：类型推导结果：i, i
    // func2(a, b);    //调用会失败，因为int和double不是完全匹配的类型
    func(f);       // 输出：类型推导结果：f
    func(f1);      // 输出：类型推导结果：f

    int arr[5];     
    func(arr);     // 输出：类型推导结果：Pi
    func(&arr[0]);  // 输出：类型推导结果：Pi
    func(&arr);     // 输出：类型推导结果：PA5_i, 这里的 "PA5" 可以理解为 "Pointer to Array of 5 elements"，而 "_i" 则表示这些元素是整型的。

    return 0;
}
