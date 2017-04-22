#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include "body.hpp"

class System
{
public:
    System();

    ///
    /// \brief Add a new body to the system
    /// \param body The new body
    ///
    void addBody(Body body);

    ///
    /// \brief Updates the whole system
    ///
    void update();

    std::string toString();


private:
    std::vector<Body> bodys_;
};

#endif // SYSTEM_HPP
