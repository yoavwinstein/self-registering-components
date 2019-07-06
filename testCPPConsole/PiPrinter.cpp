#include "PiPrinter.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>


void PiPrinter::print() {
    std::cout << M_PI << std::endl;
}

static RegisterConsolePrinter<PiPrinter> y;