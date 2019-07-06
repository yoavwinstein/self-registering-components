#pragma once
#include <vector>
#include <functional>
#include <memory>


template <typename BaseClass>
class ComponentRegistry {
public:
    using RegistrarPtrType = std::unique_ptr<BaseClass>;
    using RegistrarCtor = RegistrarPtrType();
    using RegistrarCtorFunc = std::function<RegistrarCtor>;
    using RegistryDB = std::vector<RegistrarCtorFunc>;

    static void registerComponent(const RegistrarCtorFunc& func) {
        if (!s_db) {
            s_db = new RegistryDB;
        }
        s_db->push_back(func);
    }

    static void unregisterComponent() {
        // Note: I'm assuming that global destruction is in reverse order.
        //       That means that pop_back will remove the correct globally registered component
        s_db->pop_back();
        if (s_db->size() == 0) {
            delete s_db;
        }
    }

    static std::vector<RegistrarPtrType> constructAll() {
        std::vector<RegistrarPtrType> ret;

        for (auto& registrarCtor : *s_db) {
            ret.push_back(registrarCtor());
        }

        return ret;
    }

private:
    static RegistryDB* s_db;
};
template <typename BaseClass>
typename ComponentRegistry<BaseClass>::RegistryDB* ComponentRegistry<BaseClass>::s_db = nullptr;
