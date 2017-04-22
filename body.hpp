#ifndef BODY_HPP
#define BODY_HPP

#include <QVector2D>
#include <string>

class System;

class Body
{
public:
    Body(std::string name, double mass, double radius,
         QVector2D initPosition, QVector2D initVelocity);

    ///
    /// \brief update method of the method
    ///
    void update(const System& system);

    std::string name() const;

    ///
    /// \brief Returns the postion of the body
    ///
    QVector2D postion() const;

    ///
    /// \brief Returns the mass of the body
    ///
    double mass() const;

    ///
    /// \brief print the body data for debug purpose
    ///
    std::string toString();

    ///
    /// \brief Gets the radius of the body
    ///
    double radius() const;

private:
    const std::string name_;
    QVector2D postion_;
    QVector2D velocity_;
    QVector2D acceleration_;

    const double mass_;
    const double radius_; // Radius decides how big the body look on string
};

#endif // BODY_HPP
