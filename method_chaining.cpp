#include<iostream>
#include<string>

class Chain{

    std::string name;

    public:

    Chain(){}
    Chain(std::string name) : name(name) {}

    Chain& hello(){
        std::cout << "Hello, " << name << std::endl;
        return *this;
    }

    Chain& bye(){
        std::cout << "Bye !" << std::endl;
        return *this;
    }
};

int main(){
    Chain c("Nexus");
    c.hello().bye(); //method chaining
    return 0;
}
