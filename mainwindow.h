#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPageSelected();

private:
    void loadPages();

    QListWidget *pageList;
    QLabel *imageLabel;
    QLabel *statusLabel;
};

#endif // MAINWINDOW_H