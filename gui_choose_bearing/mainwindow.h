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

    QPushButton *btn_quit = new QPushButton("EXIT");

    QHBoxLayout *h_layout_bearing_name = new QHBoxLayout;

    //bearing_diameter_outer_race
    QHBoxLayout *h_layout_bearing_diameter_outer_race = new QHBoxLayout;
    QLabel *label_bearing_diameter_outer_race = new QLabel("Enter bearing diameter outer race: ");
    QLineEdit *line_bearing_diameter_outer_race = new QLineEdit();
    QPushButton *btn_bearing_diameter_outer_race = new QPushButton("Button");

    QHBoxLayout *h_layout_btn_exit = new QHBoxLayout;

    QVBoxLayout *v_layout = new QVBoxLayout;



public slots:
    void press_btn();
    void press_btn_bearing_diameter_outer_race();
private slots:

};

#endif // MAINWINDOW_H
