#include "body.hpp"

Body::Body(std::string name, double mass, double radius,
           QVector2D initPosition, QVector2D initVelocity) :
    name_{name},
    postion_{initPosition},
    velocity_{initVelocity},
    acceleration_{},
    mass_{mass},
    radius_{radius}
{

}

void Body::update(const System& system)
{
    // Todo: Computes the net force

    // Todo: Updates the acceleration

    // Todo: Updates the velocity and position
}

std::string Body::name() const
{
    return name_;
}

QVector2D Body::postion() const
{
    return postion_;
}

double Body::mass() const
{
    return mass_;
}

std::string Body::toString()
{
    return "Body:" + name_ +
            "\nposition " + std::to_string(postion_.x()) + ", " + std::to_string(postion_.y()) +
            "\nvelocity " + std::to_string(velocity_.x()) + ", " + std::to_string(velocity_.y()) +
            "\nacceleration " + std::to_string(acceleration_.x()) + ", " + std::to_string(acceleration_.y()) +
            "\nmass " +  std::to_string(mass_);

}

double Body::radius() const
{
    return radius_;
}
