#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MainLayout->addWidget(Line);
    MainLayout->addWidget(Btn_1);
    MainLayout->addWidget(label);

    MainWidget->setLayout(MainLayout);
    setCentralWidget(MainWidget);

    connect(Btn_1, SIGNAL(clicked()), this, SLOT(press_btn()));
}

void MainWindow::press_btn()
{
    QString s = Line->text();
//    qDebug() << "s - " << s;
//    Btn_1->setText(s);

    //set name bearing from user
    bearing.set_bearing_name(s.toStdString());

    //for debug
    qDebug() << "set_bearing_name - " << QString::fromStdString(bearing.bearing_name());

//    //convert from QString to std::string
//    std::string utf8_text = s.toUtf8().constData();
//    std::string utf8_text_v2 = s.toStdString();

//    //for test
//    std::cout << "utf8_text ==" << utf8_text << std::endl;
//    std::cout << "utf8_text_v2 ==" << utf8_text_v2 << std::endl;

//    //convert from std::string to QString
//    QString str = QString::fromStdString(utf8_text_v2);
//    qDebug() << "str.fromStdString(utf8_text_v2) - " << str;
}


MainWindow::~MainWindow()
{

}
