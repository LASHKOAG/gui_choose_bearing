#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QWidget"
#include "QPushButton"
#include "QGridLayout"
#include "QLineEdit"

#include <QDebug>
#include <QString>
#include "proto_bearing.pb.h"
//#include <iostream>
#include <QLabel>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget *MainWidget = new QWidget;
    QPushButton *Btn_1 = new QPushButton("Button");
    QGridLayout *MainLayout = new QGridLayout;
    QLineEdit *Line = new QLineEdit();

    QLabel *label = new QLabel("Enter bearing name: ");
    package_bearing::Message_bearing bearing;

public slots:
    void press_btn();
};

#endif // MAINWINDOW_H
