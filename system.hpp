#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <memory>
#include <vector>
#include <QVector2D>
#include <QColor>

#include "body.hpp"

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

    std::vector<std::shared_ptr<Body> > bodys() const;

    int getDelta() const;
    void setDelta(int value);

private:
    std::vector<std::shared_ptr<Body>> bodies_;
    MainWindow *const mainWindow_; // Back pointer to the main window
    int delta_ = 50; // Time interval is ms

};

#endif // SYSTEM_HPP
