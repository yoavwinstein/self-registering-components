#pragma once
#include "ComponentRegistry.h"


template <typename BaseClass, typename DerivedClass>
class RegisterComponent {
public:
    using CurrentRegistry = ComponentRegistry<BaseClass>;
    RegisterComponent() {
        CurrentRegistry::registerComponent([]() -> typename CurrentRegistry::RegistrarPtrType {
            return std::make_unique<DerivedClass>();
                                           });
    }

    ~RegisterComponent() {
        CurrentRegistry::unregisterComponent();
    }
};
