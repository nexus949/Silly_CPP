// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

void func(int arr[]){
    arr[0] = 5;
    std::cout << &arr[0] << std::endl;
}

int main(){
    // int a = 10;
    // int b = 20;
    // int* arr[] = { &a, &b };
    // int** pp = arr;

    // std::cout << "addresses:" << std::endl;
    // std::cout << "address of arr: " << &arr << std::endl;
    // std::cout << "value of pp: " << *pp << std::endl;
    // // std::cout << "address of ++*pp: " << &(++*pp) << std::endl;
    // std::cout << ++*pp << std::endl;
    // std::cout << "address of arr: " << &arr << std::endl;
    // std::cout << "address of a: " << &a << std::endl;
    // std::cout << "address of b: " << &b << std::endl;

    // std::cout << **pp << std::endl;  // prints 10 (a)
    // ++*pp;                           // *pp now points to b
    // std::cout << **pp << std::endl;  // prints 20 (b)

    // int a = 3;
    // int* ptr = &a;
    // int** itr = &ptr;

    // // std::cout << **itr << std::endl;
    // std::cout << *itr << std::endl;
    // std::cout << &a << std::endl;

    // std::cout << ptr << " " << &a << std::endl;

    // int arr[] = { 3, 7 };
    // int* ptr = arr; //decay to &arr[0] !
    // ptr += 1;
    // arr = (arr + 1); //illegal, compile error
    // std::cout << *(arr + 1) << std::endl;

    // int* pointer = new int;
    // *pointer = 25;
    // std::cout << *pointer << std::endl;
    // pointer += 1;
    // std::cout << *pointer << std::endl;

    // int* ptr = reinterpret_cast<int*>(&arr);
    // std::cout << "Before update: " << arr[0] << std::endl;
    // func(arr);
    // std::cout << &arr[0] << std::endl;
    // std::cout << "After update: " << arr[0] << std::endl;

    // std::cout << &arr << std::endl;
    // std::cout << &arr[0] << std::endl;

    // int* ptr = &arr;
    return 0;
}
