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
#include <iostream>
#include <fstream>
#include <QLabel>
#include <QCoreApplication>
#include <QFile>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget *MainWidget = new QWidget;
    QGridLayout *MainLayout = new QGridLayout;
    package_bearing::Message_bearing bearing;

    //bearing_name
    QHBoxLayout *h_layout_bearing_name = new QHBoxLayout;
    QLabel *label_bearing_name = new QLabel("Enter bearing name: ");
    QLineEdit *line_bearing_name = new QLineEdit();
    QPushButton *btn_bearing_name = new QPushButton("Button");

    //bearing_diameter_outer_race
    QHBoxLayout *h_layout_bearing_diameter_outer_race = new QHBoxLayout;
    QLabel *label_bearing_diameter_outer_race = new QLabel("Enter bearing diameter outer race: ");
    QLineEdit *line_bearing_diameter_outer_race = new QLineEdit();
    QPushButton *btn_bearing_diameter_outer_race = new QPushButton("Button");

    //exit
    QHBoxLayout *h_layout_btn_exit = new QHBoxLayout;
    QPushButton *btn_quit = new QPushButton("EXIT");

    QVBoxLayout *v_layout = new QVBoxLayout;

    //запись измерений в файл
    //Возвращает 0 в случае успеха либо отрицательные значения
    //Первый аргумент - это путь к месторасположению файла, 2 ой - полученная структура от slave устройства
    qint32 write_file (QString);

public slots:
    void press_btn_bearing_name();
    void press_btn_bearing_diameter_outer_race();
private slots:

};

#endif // MAINWINDOW_H
