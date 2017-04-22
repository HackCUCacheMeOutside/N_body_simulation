#include <algorithm>

#include "system.hpp"

System::System()
{

}

void System::addBody(Body body)
{
    bodys_.push_back(std::move(body));
}

void System::update()
{
    for (auto i = bodys_.begin(), end = bodys_.end(); i != end; ++i) {
        i->update(*this);
    }
}

std::string System::toString()
{
    std::string string;
    for (auto i = bodys_.begin(), end = bodys_.end(); i != end; ++i) {
        string += i->toString() + "\n";
    }

    return string;
}
