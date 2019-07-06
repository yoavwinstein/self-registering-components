#include "HelloWorldPrinter.h"
#include <iostream>


void HelloWorldPrinter::print() {
    std::cout << "Hello, world!" << std::endl;
}

static RegisterConsolePrinter<HelloWorldPrinter> x;
