#pragma once
#include "ConsolePrinter.h"


class PiPrinter : public ConsolePrinter {
public:
    PiPrinter() {}
    virtual void print() override;
};
