#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <memory>
#include <vector>
#include "body.hpp"

constexpr double delta = 0.005; // Time interval

class Body;
class MainWindow;

class System
{
public:
    explicit System(MainWindow *mainWindow);

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


    std::vector<std::shared_ptr<Body> > bodys() const;

private:
    std::vector<std::shared_ptr<Body>> bodies_;
    MainWindow *const mainWindow_; // Back pointer to the main window
};

#endif // SYSTEM_HPP
