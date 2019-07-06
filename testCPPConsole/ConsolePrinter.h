#pragma once
#include "RegisterComponent.h"


class ConsolePrinter {
public:
    ConsolePrinter() = default;
    virtual ~ConsolePrinter() = default;
    virtual void print() = 0;
};
using ConsolePrintersRegistry = ComponentRegistry<ConsolePrinter>;
template <typename SomeDerived>
using RegisterConsolePrinter = RegisterComponent<ConsolePrinter, SomeDerived>;
