#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionReset_triggered();
    void on_actionQuit_triggered();
    void on_actionFemale_triggered();
    void on_actionMale_triggered();
    void calculate_bmi();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
