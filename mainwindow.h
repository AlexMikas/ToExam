#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <model.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Model model;

private:
    Ui::MainWindow *ui;
signals:
    void tableView();
    void resultOutput();

private slots:
    void selectFileClicked();
    void filterClicked();
    void tableViewWindow();
};

#endif // MAINWINDOW_H
