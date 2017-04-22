#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGraphicsView>
#include "system.hpp"

namespace Ui {
class MainWindow;
}

class QGraphicsView;
class BodyGraphicsItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /// @brief Gets the graphics scene
    QGraphicsScene* scene() const;

    /// @brief Gets the system of main window
    System system() const;

    /// @brief Updates the data
    void update();

private:
    Ui::MainWindow *ui_;
    QGraphicsView *graphicsView_;
    std::unique_ptr<QGraphicsScene> scene_;
    System system_;
};

#endif // MAINWINDOW_HPP
