#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    h_layout_bearing_name->addWidget(label_bearing_name);
    h_layout_bearing_name->addWidget(line_bearing_name);
    h_layout_bearing_name->addWidget(btn_bearing_name);

    h_layout_bearing_diameter_outer_race->addWidget(label_bearing_diameter_outer_race);
    h_layout_bearing_diameter_outer_race->addWidget(line_bearing_diameter_outer_race);
    h_layout_bearing_diameter_outer_race->addWidget(btn_bearing_diameter_outer_race);

    h_layout_btn_exit->addWidget(btn_quit);

    v_layout->addLayout(h_layout_bearing_name);
    v_layout->addLayout(h_layout_bearing_diameter_outer_race);

    v_layout->addLayout(h_layout_btn_exit);

    MainWidget->setLayout(v_layout);

//    MainLayout->addWidget(Line);
//    MainLayout->addWidget(Btn_1);
//    MainLayout->addWidget(label);

//    MainLayout->addWidget(btn_quit);


    MainWidget->setLayout(MainLayout);
    setCentralWidget(MainWidget);

    connect(btn_bearing_name, SIGNAL(clicked()), this, SLOT(press_btn_bearing_name()));

    connect(btn_bearing_diameter_outer_race, SIGNAL(clicked()), this, SLOT(press_btn_bearing_diameter_outer_race()));

    //quit
    //    connect(btn_quit, SIGNAL(clicked()), this, SLOT(QCoreApplication::quit() ));
    connect(btn_quit, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);
}

void MainWindow::press_btn_bearing_name()
{
    QString s = line_bearing_name->text();
//    qDebug() << "s - " << s;
//    Btn_1->setText(s);

    //check entered field empty or has info
    if(s.isEmpty()){
        qDebug() << "set_bearing_name - is empty";
    }else{
        //if field no empty then set name bearing from user
        bearing.set_bearing_name(s.toStdString());

        //for debug
        qDebug() << "set_bearing_name - " << QString::fromStdString(bearing.bearing_name());
    }

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

void MainWindow::press_btn_bearing_diameter_outer_race()
{
    //initializing
    bearing.set_bearing_diameter_outer_race(0);

    //get information from user
    QString s = line_bearing_diameter_outer_race ->text();

    //convert from Qstring to number
    qint32 dec = s.toInt();
    qDebug() << "dec = " << dec;

    //check  this letter or number?
    if(dec > 0){
        //if entered info is number then:
        bearing.set_bearing_diameter_outer_race(s.toInt());

        qDebug() << "bearing.set_bearing_diameter_outer_race : " << bearing.bearing_diameter_outer_race();
        //        std::string str = bearing.SerializeAsString();
        //        std::cout << "str : " << str;

        //************************ I variant ******************************************
        //write to file through SerializeToOstream
        //ios_base::trunc - удалить содержимое файла, если он существует
        std::fstream out("/home/dev/Desktop/sl_pb", std::ios::out | std::ios::trunc | std::ios::binary);
        bearing.SerializeToOstream(&out);
        out.close();
        out.flush();

        //give chmod 777
        system("sudo chmod 777 /home/dev/Desktop/sl_pb");

        //write from file through ParseFromIstream in field of protobuf class
        std::fstream in("/home/dev/Desktop/sl_pb", std::ios::in | std::ios::binary);
        package_bearing::Message_bearing bearing2;
        bearing2.ParseFromIstream(&in);
                std::cout << "Read from file ->bearing2.bearing_name() : " << bearing2.bearing_name() << std::endl;
                std::cout << "Read from file ->bearing2.bearing_diameter_outer_race() : " << bearing2.bearing_diameter_outer_race() << std::endl;
        in.close();
        in.flush();
        //***************************************************************************************

//        QFile *file = new QFile("/home/dev/Desktop/serial_pb");
//            if(!file->open(QFile::Append | QFile::Text)){
//                qDebug() << " Could not open file for writing";
//            }
//            char filename[] = "/home/dev/Desktop/serial_pb";
//        bearing.SerializePartialToOstream(filename);
//            //            QTextStream out(file);
//            //            out << "radius" ;
//                        qDebug() << " file was written";
//                        file->flush();
//                        file->close();
//                    delete file;

//        QFile *file = new QFile("/home/dev/Desktop/ttttt");
//            if(!file->open(QFile::Append | QFile::Text)){
//                qDebug() << " Could not open file for writing";
//            }

//            QTextStream out(file);
//            out << "radius" ;
//            qDebug() << " file was written";
//            file->flush();
//            file->close();
//        delete file;

    }else{
        //give windows with WARNING: you entered wrong size
        qDebug() << "bearing.set_bearing_diameter_outer_race : no valid parameter";
    }


}


qint32 MainWindow::write_file (QString filename)
{
    QFile *file = new QFile(filename);

    if(!file->open(QFile::Append | QFile::Text)){
        qDebug() << " Could not open file for writing";
        return -1;
    }

    QTextStream out(file);

//    out << measurementNumber << ";";
//    out << QTime::currentTime().toString() << ";";
//    out << data.bus_voltage_mV << ";";
//    out << data.current_mA << ";";
//    out << data.warning_low_battery << ";";
//    out << data.flag_status_charger << ";";
//    out << "\n";
//    measurementNumber++;

    file->flush();
    file->close();
    delete file;
    return 0;
}

MainWindow::~MainWindow()
{

}
