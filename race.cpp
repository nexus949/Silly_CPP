#include <iostream>

void Function1();
void Function2();
static int count = 0;

void Function1(){
    std::cout << "Function 1 called !, call count : " << count << std::endl;
    ++count;
    Function2();
}

void Function2(){
    std::cout << "Function 2 called !, call count : " << count << std::endl;
    ++count;
    Function1();
}

int main(){

    Function1();

    return 0;
}
