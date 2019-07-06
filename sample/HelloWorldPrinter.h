#pragma once
#include "ConsolePrinter.h"


class HelloWorldPrinter : public ConsolePrinter {
public:
    HelloWorldPrinter() = default;

    virtual void print() override;
};
