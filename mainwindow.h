#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DirectoryMonitor.h"
#include "SmartPtr.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addDirectory();
    void removeDirectory();
    void setLogFile();
    void showLogContents();
    void updateLogDisplay();

private:
    void updateDirectoryList();

    Ui::MainWindow *ui;
    smart_ptr<DirectoryMonitor> monitor;
};

#endif // MAINWINDOW_H
