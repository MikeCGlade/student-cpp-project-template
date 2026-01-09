#include <iostream>
#include "include/Entity.h"

int main(){
    std::cout << "Hello World!" << std::endl; 

    Entity en("Ant");

    en.showEntity(); 
    
    return 0;
}