#include "mainwindow.h"

QDataStream& operator << (QDataStream &out, const package_bearing::Message_bearing &pb)
{
    std::string bearing_message_str = pb.SerializeAsString();
    QByteArray ba(bearing_message_str.data(), int(bearing_message_str.size()));
//    out << QString("This bearing");
//    out << 0x10;
    out << ba;
    return out;
}

QDataStream& operator >> (QDataStream &in, package_bearing::Message_bearing &pb)
{
//    std::string bearing_message_str = pb.SerializeAsString();
    QByteArray ba_in;
    QString tmpStr;
    qint32 ver = 0;
//    in >> tmpStr;
//    Q_ASSERT(tmpStr != QString("This bearing"));
//    in >> ver;
//    switch (ver) {
//    case 0x10:
//        dfdfdf
//        break;
//    default:
//        Q_ASSERTbreak;


//    }
//    if 0x10;
    in >> ba_in;

//    std::string str_bearing_after = ba.toStdString();
//    package_bearing::Message_bearing bearing22;
//    package_bearing::Message_bearing pb;

//    bearing22.ParseFromString(str_bearing_after);
//    pb.ParseFromString(str_bearing_after);

//    if(!pb.ParseFromString(str_bearing_after)){
//        qDebug() << "OK";
//    }

//qDebug() << "OK";
//    std::cout << "Read from Qfile ->bearing2.bearing_name() : " << bearing22.bearing_name() << std::endl;
//    std::cout << "Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << bearing22.bearing_diameter_outer_race() << std::endl;
//    std::cout << "Read from Qfile ->bearing2.bearing_name() : " << pb.bearing_name() << std::endl;
//    std::cout << "Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << pb.bearing_diameter_outer_race() << std::endl;

    return in;
}


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

        //********** variant QByteArray  <-> std::string
        //Serialize protobuf
        QByteArray dataQ;
        QDataStream streamQ(&dataQ, QIODevice::ReadWrite);
        streamQ << bearing;

        package_bearing::Message_bearing bearing3;

        QByteArray dataQ2;
        QDataStream streamQ2(&dataQ, QIODevice::ReadWrite);
        streamQ2 >> dataQ2;


        std::string str_bearing_after = dataQ2.toStdString();
        bearing3.ParseFromString(str_bearing_after);

        std::cout << "Read from Qfile ->bearing2.bearing_name() : " << bearing3.bearing_name() << std::endl;
        std::cout << "Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << bearing3.bearing_diameter_outer_race() << std::endl;
        //***************************************************

    }else{
        //give windows with WARNING: you entered wrong size
        qDebug() << "bearing.set_bearing_diameter_outer_race : no valid parameter";
    }


}


MainWindow::~MainWindow()
{

}
