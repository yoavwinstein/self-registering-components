# Self Registering Components
A simple library which allows registration of components from within their compilation unit

## Motivation
Are you tired of big main functions looking like this?

```cpp
#include "ComponentA.h"
#include "ComponentB.h"
#include "ComponentC.h"
// ... more


void initializeComponents() {
    components.push_back(ComponentA);
    components.push_back(ComponentB);
    components.push_back(ComponentC);
    // ... more
}
```

As more files are being included and used, this compilation unit gets bigger and more cyclic dependencies might show up, making a tangle of dependencies. Dependencies can be described by the following graph:

TBD

Well, this library gives you an opportunity to make each component register itself within a global registry, with a small runtime overhead, replacing the big main registering cpp file with code in each component's translation unit. Consider the following graph:

TBD

## Installation
clone and add the `inc` directory to your include directories

## Usage
Given the following base class:
```cpp
class ComponentBase {
    // ...implementation
};
```

and the following derived class:
```cpp
class DerivedComponent : public ComponentBase {
    // ...implementation
};
```

Add the following code below your base class:
```cpp
using MyComponentRegistry = ComponentRegistry<ComponentBase>;
template <typename SomeDerived>
using RegisterMyComponent = RegisterComponent<ComponentBase, SomeDerived>;
```

and the following code below the derived class:
```cpp
static RegisterMyComponent<DerivedComponent> x;
```
This can repeated for every derived class that needs registration.

Finally, wherever you want to instanciate the registered components just call:
```cpp
auto allComponents = MyComponentRegistry::constructAll();
```
And thats it!
