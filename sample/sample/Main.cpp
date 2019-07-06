#include "ConsolePrinter.h"
#include <iostream>


int main() {
    std::cout << "main() called" << std::endl;
    auto allComponents = ConsolePrintersRegistry::constructAll();
    for (auto& component : allComponents) {
        component->print();
    }
    return 0;
}

