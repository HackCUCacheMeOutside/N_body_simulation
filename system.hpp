#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <memory>
#include <vector>
#include <QVector2D>
#include <QColor>

#include "body.hpp"

constexpr int delta = 50; // Time interval is ms

class Body;
class MainWindow;

class System
{
public:
    explicit System(MainWindow *mainWindow);

    ///
    /// \brief Add a new body to the system
    /// \param body The new body
    /// \param color The color of the body
    ///
    void addBody(Body body, const QColor& color);

    ///
    /// \brief Clear all the bodies
    ///
    void clearBody();

    ///
    /// \brief Updates the whole system
    ///
    void update();

    std::string toString();


    // Gets center of mass of the whole system
    QVector2D centerOfMass();


    std::vector<std::shared_ptr<Body> > bodys() const;

private:
    std::vector<std::shared_ptr<Body>> bodies_;
    MainWindow *const mainWindow_; // Back pointer to the main window

};

#endif // SYSTEM_HPP
