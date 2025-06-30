#include<iostream>

class _1Byte{
    public:
    char a = 'c';

    _1Byte(){}
    operator char() const { //overload for the char store
        return a;
    }

    void print_a(){
        std::cout << a << std::endl;
    }
};

class _MoreThan1Byte{
    public:
    int x = 450; //more than a byte can store

    _MoreThan1Byte(){}
    operator int() const {
        return x; //gets truncated and only the least 8 bits are stored in a byte(char)
    }

    void print_x(){
        std::cout << x << std::endl;
    }
};

int main(){

    // int x = 64;
    // int* ptr = &x;
    // std::cout << "Value at x: " << *ptr << std::endl;

    // char* ch = reinterpret_cast<char*>(&x);
    // std::cout << "Value read as a char*: " << std::endl;
    // std::cout << *ch << std::endl;
    // ch++;
    // std::cout << *ch << std::endl;
    // ch++;
    // std::cout << *ch << std::endl;
    // ch++;
    // std::cout << *ch << std::endl;
    // ch++;  //out of bounds memory access
    // std::cout << *ch << std::endl;

    // char ch = 'A';
    // char* c_ptr = &ch;
    // std::cout << "Value at ch: " << *c_ptr << std::endl;

    // int* i_ptr = reinterpret_cast<int*>(&ch);
    // std::cout << "Value read as a int*: " << std::endl;
    // std::cout << *i_ptr << std::endl;

    // char ch = 'A';
    // char* c_ptr = &ch;

    // float* f_ptr = reinterpret_cast<int*>(&ch); //compilation error, Template arg type must be same as lvalue type !

    // char c = 300;  //will cause overflow as 300 is bigger than a byte (compile error)
    // std::cout << c << std::endl;

    _1Byte b;
    char ch = b;
    std::cout << ch << std::endl; //just prints the value of the particular thing stored

    _MoreThan1Byte m;
    char ch_2 = m; //will cause overflow ? No actually, not here ! C++ trucates the bits ! Only the 8 lower bits of 450 is kept !
    std::cout << ch_2 << std::endl; //That is printed !

    //storing a object in a char is not trivial ! Need to overload the () operator and define everything manually what to store and what not to store.
    //If it can be stored it will be else will cause an overflow or some other issue!
    //Every class and object is just collection of primitive data types so more or less we need to return or manipulate primitives in the overload !

    /*
    But why does this works :
    object o;
    char ch = o; //no overflow (C++ trucates bits and keep the 8 least bits)
    OR
    int x = 300;
    char ch = x; //no overflow (C++ trucates bits and keep the 8 least bits)

    and this doesn't ?:
    char ch = 300; //overflow

    Because char ch = 300; Here 300 is a rvalue and C++ knows this at compile time and thus throws an overflow error !
    BUT
    object o;
    char ch = o; Here o is a lvalue and C++ does not its content at compile time therefore at runtime, it truncates the bits and keeps the 8 least bits
    and no overflow !

    C++ is strict with literals (rvalues), but lenient with lvalues. This is part of C++'s design — it favors flexibility at runtime,
    while enforcing safety where it can at compile time.
    */
    return 0;
}
