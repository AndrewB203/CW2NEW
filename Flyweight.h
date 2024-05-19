#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>
#include <string>
#include <vector>

class Flyweight {
public:
    Flyweight(const std::string& state);
    virtual ~Flyweight();
    virtual void Operation(const std::string& state) = 0;
    std::string GetState() const;

protected:
    std::string _state;
};

class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight(const std::string& state);
    void Operation(const std::string& state) override;
};

class FlyweightFactory {
public:
    Flyweight* GetFlyweight(const std::string& key);

private:
    std::vector<Flyweight*> _flyweights;
};

#endif // FLYWEIGHT_H
