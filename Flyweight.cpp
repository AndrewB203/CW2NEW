#include "Flyweight.h"

Flyweight::Flyweight(const std::string& state) : _state(state) {}

Flyweight::~Flyweight() {}

std::string Flyweight::GetState() const {
    return _state;
}

ConcreteFlyweight::ConcreteFlyweight(const std::string& state) : Flyweight(state) {
    std::cout << "ConcreteFlyweight Build..." << _state << std::endl;
}

void ConcreteFlyweight::Operation(const std::string& state) {
    std::cout << "ConcreteFlyweight " << GetState() << " \\ " << state << std::endl;
}

Flyweight* FlyweightFactory::GetFlyweight(const std::string& key) {
    for (auto& flyweight : _flyweights) {
        if (flyweight->GetState() == key) {
            std::cout << "already created by users..." << std::endl;
            return flyweight;
        }
    }
    Flyweight* newFlyweight = new ConcreteFlyweight(key);
    _flyweights.push_back(newFlyweight);
    return newFlyweight;
}

/*int main() {
    FlyweightFactory *fc = new FlyweightFactory();
    Flyweight *fw1 = fc->GetFlyweight("hello");
    Flyweight *fw2 = fc->GetFlyweight("world");
    Flyweight *fw3 = fc->GetFlyweight("hello");

    delete fw1;
    delete fw2;
    //delete fw3;
    delete fc;

    return 0;
}*/
