#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
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
    System* system() const;

    /// @brief Updates the data
public slots:
    void update();

private:
    Ui::MainWindow *ui_;
    QGraphicsView *graphicsView_;
    std::unique_ptr<QGraphicsScene> scene_;
    std::unique_ptr<System> system_;

    QTimer timer_; // Timer for graphics
    QTimer update_timer_; // Timer for update
};

#endif // MAINWINDOW_HPP
