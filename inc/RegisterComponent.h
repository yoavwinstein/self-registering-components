#ifndef YWNS_REGISTER_COMPONENT_H_
#define YWNS_REGISTER_COMPONENT_H_

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
#endif  // YWNS_REGISTER_COMPONENT_H_
