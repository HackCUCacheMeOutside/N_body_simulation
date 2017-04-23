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
    QVector2D position() const;

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

    ///
    /// \brief Gets id of the body
    ///
    std::uint64_t id() const;

private:
    std::uint64_t id_; // Unique integar id for each body
    const std::string name_;
    QVector2D position_;
    QVector2D velocity_;
    QVector2D acceleration_;

    double mass_;
    const double radius_; // Radius decides how big the body look on string
};

#endif // BODY_HPP
