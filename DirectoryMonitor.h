#ifndef DIRECTORYMONITOR_H
#define DIRECTORYMONITOR_H

#include "smartptr.h"
#include <QObject>
#include <QFileSystemWatcher>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class DirectoryMonitor : public QObject {
    Q_OBJECT

public:
    explicit DirectoryMonitor(QObject *parent = nullptr) : QObject(parent), watcher(new QFileSystemWatcher(this)) {
        connect(watcher.get(), &QFileSystemWatcher::directoryChanged, this, &DirectoryMonitor::logDirectoryChange);
        connect(watcher.get(), &QFileSystemWatcher::fileChanged, this, &DirectoryMonitor::logFileChange);
    }

    void setLogFile(const QString &path) {
        logFilePath = path;
    }

    const QString& getLogFilePath() const {
        return logFilePath;
    }

    void addDirectory(const QString &path) {
        if (!watcher->directories().contains(path)) {
            watcher->addPath(path);
            logChange("Monitoring started for: " + path);
        }
    }

    void removeDirectory(const QString &path) {
        if (watcher->directories().contains(path)) {
            watcher->removePath(path);
            logChange("Monitoring stopped for: " + path);
        }
    }

    QStringList monitoredDirectories() const {
        return watcher->directories();
    }

signals:
    void logUpdated();

private slots:
    void logDirectoryChange(const QString &path) {
        logChange("Directory changed: " + path);
        emit logUpdated();
    }

    void logFileChange(const QString &path) {
        logChange("File changed: " + path);
        emit logUpdated();
    }

private:
    void logChange(const QString &message) {
        if (logFilePath.isEmpty()) return;

        smart_ptr<QFile> file(new QFile(logFilePath));
        if (file->open(QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(file.get());
            stream << QDateTime::currentDateTime().toString(Qt::ISODate)
                   << " - " << message << "\n";
        }
    }

    smart_ptr<QFileSystemWatcher> watcher;
    QString logFilePath;
};

#endif // DIRECTORYMONITOR_H
