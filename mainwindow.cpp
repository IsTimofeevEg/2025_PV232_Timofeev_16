#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), monitor(new DirectoryMonitor(this)) {
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addDirectory);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::removeDirectory);
    connect(ui->setLogButton, &QPushButton::clicked, this, &MainWindow::setLogFile);
    connect(ui->showLogButton, &QPushButton::clicked, this, &MainWindow::showLogContents);
    connect(monitor.get(), &DirectoryMonitor::logUpdated, this, &MainWindow::updateLogDisplay);

    updateDirectoryList();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addDirectory() {
    QString dir = ui->directoryEdit->text();
    if (!dir.isEmpty()) {
        monitor->addDirectory(dir);
        updateDirectoryList();
    }
}

void MainWindow::removeDirectory() {
    QString dir = ui->directoryEdit->text();
    if (!dir.isEmpty()) {
        monitor->removeDirectory(dir);
        updateDirectoryList();
    }
}

void MainWindow::setLogFile() {
    QString file = ui->logFileEdit->text();
    if (!file.isEmpty()) {
        monitor->setLogFile(file);
        ui->statusbar->showMessage("Log file set to: " + file, 3000);
    }
}

void MainWindow::showLogContents() {
    if (monitor->getLogFilePath().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Лог-файл не указан");
        return;
    }
    updateLogDisplay();
}

void MainWindow::updateLogDisplay() {
    smart_ptr<QFile> file(new QFile(monitor->getLogFilePath()));
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть лог-файл");
        return;
    }

    QTextStream in(file.get());
    ui->logTextEdit->setPlainText(in.readAll());
}

void MainWindow::updateDirectoryList() {
    ui->directoryList->clear();
    ui->directoryList->addItems(monitor->monitoredDirectories());
}
