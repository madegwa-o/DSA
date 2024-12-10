#include <iostream>

int main(){

    std::string name = "Oscar";


    std::string *pName = &name;


    std::cout << name << std::endl;
    std::cout << &name << std::endl;
    std::cout << pName << std::endl;
    std::cout << *pName << std::endl;


    return 0;
}