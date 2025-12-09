#include "prototype/cpp/prototype.h"
#include <string>

Cloneable::Cloneable(const std::string &name_):name(name_) {}

std::string Cloneable::get_name() {
    return this->name;
}


Cloneable1* Cloneable1::Clone() {
    return new Cloneable1(this->name);
}

void PrototypeManager::set(const std::string &key, Cloneable *value) {
    mp[key] = value;
}

Cloneable* PrototypeManager::get(const std::string &key) const {
    auto it = mp.find(key);
    return it != mp.end() ? it->second : nullptr;
}

PrototypeManager::~PrototypeManager() {
    for (auto i : mp) {
        if (i.second != nullptr) {
            delete i.second;
        }
    }
}
