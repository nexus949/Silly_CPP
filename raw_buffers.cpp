#include<iostream>

int main(){

    char buffer[16]; //stack allocated buffer ! Yes its a char array of size 16 bytes !

    //Here we're storing the value 145 at 'buffer' (which points to the start of the char buffer[16]).
    //we do *reinterpret_cast<int*> because we are saying store the value 145. But to store or modify values using a pointer, we must dereference it.
    //thats why the * at the begenning ! We are dereferencing a char* and reinterpreting it as a int* but its still a pointer so dereference it and store the value !
    //if no dereferencing its saying like int* pointer = 145 which is not a valid syntax !
    //we are just converting a char* to a int* to store 145 !
    //the whole thing is a pointer and we need to derefernce it to store a value ! Thats it ! 145 is not a address it is a value so we must dereference the pointer to store the value !
    *reinterpret_cast<int*>(buffer) = 300;

    std::cout << static_cast<int>(buffer[0]) << std::endl;
    std::cout << static_cast<int>(buffer[1]) << std::endl;
    std::cout << static_cast<int>(buffer[2]) << std::endl;
    std::cout << static_cast<int>(buffer[3]) << std::endl;
    return 0;
}
