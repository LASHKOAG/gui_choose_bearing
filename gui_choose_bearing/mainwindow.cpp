#include "mainwindow.h"

#include <QChar>
#include <QVector>


QDataStream& operator << (QDataStream &out, const package_bearing::Message_bearing &pb)
{
    std::string bearing_message_str = pb.SerializeAsString();
    QByteArray ba(bearing_message_str.data(), int(bearing_message_str.size()));
    out << QString("This bearing");
    out << 0x10;
    out << ba;
    return out;
}

QDataStream& operator >> (QDataStream &in, const package_bearing::Message_bearing &pb)
{
//    std::string bearing_message_str = pb.SerializeAsString();
    QByteArray ba;
    QString tmpStr;
    qint32 ver = 0;
    in >> tmpStr;
//    Q_ASSERT(tmpStr != QString("This bearing"));
    in >> ver;
//    switch (ver) {
//    case 0x10:
//        dfdfdf
//        break;
//    default:
//        Q_ASSERTbreak;


//    }
//    if 0x10;
    in >> ba;

    std::string str_bearing_after;
    str_bearing_after = ba.toStdString();

//    package_bearing::Message_bearing bearing2;
//    package_bearing::Message_bearing pb;

//    pb.ParseFromString(str_bearing_after);

//    std::cout << "Read from Qfile ->bearing2.bearing_name() : " << bearing2.bearing_name() << std::endl;
//    std::cout << "Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << bearing2.bearing_diameter_outer_race() << std::endl;
    std::cout << "Read from Qfile ->bearing2.bearing_name() : " << pb.bearing_name() << std::endl;
    std::cout << "Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << pb.bearing_diameter_outer_race() << std::endl;

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
        //        std::string str = bearing.SerializeAsString();
        //        std::cout << "str : " << str;

//        //************************ I variant ******************************************
        ////this case is the best way
//        //write to file through SerializeToOstream
//        //ios_base::trunc - удалить содержимое файла, если он существует
//        std::fstream out("/home/dev/Desktop/sl_pb", std::ios::out | std::ios::trunc | std::ios::binary);
//        bearing.SerializeToOstream(&out);
//        out.close();
//        out.flush();

//        //give chmod 777
//        system("sudo chmod 777 /home/dev/Desktop/sl_pb");

//        //write from file through ParseFromIstream in field of protobuf class
//        std::fstream in("/home/dev/Desktop/sl_pb", std::ios::in | std::ios::binary);
//        package_bearing::Message_bearing bearing2;
//        bearing2.ParseFromIstream(&in);
//                std::cout << "Read from file ->bearing2.bearing_name() : " << bearing2.bearing_name() << std::endl;
//                std::cout << "Read from file ->bearing2.bearing_diameter_outer_race() : " << bearing2.bearing_diameter_outer_race() << std::endl;
//        in.close();
//        in.flush();
        //***************************************************************************************

//        //============== II variant QFile QString <-> std::string ==========================================
//        //this variant don`t work with value of bearing_diameter_outer_race > 127
//        std::string bearing_message_str = bearing.SerializeAsString();
//            std::cout << "bearing_message_str : " << bearing_message_str << std::endl;
//        //get Q-string
//        QString bearing_message_Qstr = QString::fromStdString(bearing_message_str);
//        qDebug() << "_> bearing_message_Qstr : " << bearing_message_Qstr;

//        //====test
//        //get std::string from Q-string
//        std::string str3 = bearing_message_Qstr.toUtf8().constData();
////        std::string str3 = bearing_message_Qstr.fromStdU16String();

////        for(int i=0; i<bearing_message_Qstr.size(); ++i){
////            str3 += bearing_message_Qstr.data();
////        }

//        for(int i=0; i<bearing_message_str.size(); ++i){
//            if(bearing_message_str != str3){
//                qDebug() << "NO MATCH " << i;
//            }else{
//                qDebug() << "MATCH " << i;
//            }
//        }

//        package_bearing::Message_bearing bearing3;
////        bearing3.ParseFromString(str3);
//        bearing3.ParseFromString(bearing_message_str);
//    //    bearing2.ParseFromString(bearing_message_str);
//        std::cout << "test -Read from Qfile ->bearing2.bearing_name() : " << bearing3.bearing_name() << std::endl;
//        std::cout << "test -Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << bearing3.bearing_diameter_outer_race() << std::endl;
//        //====end test

//         QFile *file = new QFile("/home/dev/Desktop/serial_pb");
//             if(!file->open(QFile::WriteOnly | QFile::Truncate)){
//                qDebug() << " Could not open file for writing";
//             }

//             system("sudo chmod 777 /home/dev/Desktop/serial_pb");

//             QDataStream stream(file);
//             stream << bearing_message_Qstr;
//             qDebug() << " file was written";
//         file->close();
////         file->flush();
//         delete file;

//         qDebug() << " ----test---";

//         QString test_str;
//         QFile *file2 = new QFile("/home/dev/Desktop/serial_pb");
//         if(!file2->open(QFile::ReadOnly)){
//            qDebug() << " Could not open file for writing";
//         }
//         QDataStream stream2(file2);
////                QByteArray data;
////                stream2 >> data;
////                test_str = QString(data);
//         stream2 >> test_str;

////         QTextStream stream3(file2);
////         stream3 >> test_str;

//         qDebug() << " file was read";
//     file2->close();
////     file2->flush();
//     delete file2;
////     qDebug() << " test_str : " << test_str;

//    package_bearing::Message_bearing bearing2;

//    std::string str2 = test_str.toStdString();

////    std::string str2 = bearing_message_str.toStdString();

////    std::string str2 = test_str.toUtf8().constData();

////    std::cout << "str2 = test_str.toStdString() : " << str2 << std::endl;

//if(bearing_message_Qstr == test_str){
//    qDebug() << " Qstring write == Qstring read ";
//}else {
//    qDebug() << " Qstring write != Qstring read ";
//}

//if(bearing_message_str == str2){
//    qDebug() << " std string write == std string read ";
//}else {
//    qDebug() << " std string write != std string read ";
//}
//    bearing2.ParseFromString(str2);
////    bearing2.ParseFromString(bearing_message_str);
//    std::cout << "Read from Qfile ->bearing2.bearing_name() : " << bearing2.bearing_name() << std::endl;
//    std::cout << "Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << bearing2.bearing_diameter_outer_race() << std::endl;

//        //==========================================================================

//    //########## III variant SerializeToArray stream_dataQByteArr #############################################
////this variant good working
//                //---before Serialize protobuf
//        //initializing massive for Serialize protobuf
//        const qint32 size_msv = 100;
//        qint32 msv_before[size_msv]={0, };

//        //Serialize protobuf
//        bearing.SerializeToArray(msv_before, size_msv);

//        //for debug
//        //        for(qint32 i=0; i<size_msv; ++i){
//        //            std::cout << msv_before[i] << std::endl;
//        //        }

//        //rewrite massive in Q-container
//        QByteArray dataQByteArr_before;
//        QDataStream stream_dataQByteArr_before(&dataQByteArr_before, QIODevice::ReadWrite);
//        //        stream3 << (int32_t)100;
//        //write value of massive to container through stream
//        for(qint32 i=0; i<size_msv; ++i){
//            stream_dataQByteArr_before << msv_before[i];
//        }

//        QString filename = "/home/dev/Desktop/serial_pb";

//        QFile *file_before = new QFile(filename);
//            if(!file_before->open(QFile::WriteOnly | QFile::Truncate)){
//                qDebug() << " Could not open file for writing";
//            }

//            system("sudo chmod 777 /home/dev/Desktop/serial_pb");

//            QDataStream stream_in_file(file_before);
//            stream_in_file << dataQByteArr_before;
//            qDebug() << " file was written";
//            file_before->close();
//        delete file_before;

//        qDebug() << " ----test---";

//        //---after
//        qint32 msv_after[size_msv]={0, };

//        QFile *file_after = new QFile(filename);
//            if(!file_after->open(QFile::ReadWrite)){
//                qDebug() << " Could not open file for writing";
//            }
//            QDataStream stream_from_file(file_after);
//            QByteArray dataQByteArr_after;
//            stream_from_file >> dataQByteArr_after;
//            qDebug() << " file was read";
//            file_after->close();
//        delete file_after;

//        QDataStream stream_dataQByteArr_after(&dataQByteArr_after, QIODevice::ReadWrite);
//        qint32 cnt = size_msv;
//        //        stream2 >> cnt; //100
//        //write value from container to through stream
//        for(qint32 i=0; i<cnt; ++i){
//            stream_dataQByteArr_after >> msv_after[i];
//        }

//        //for debug
////        for(qint32 i=0; i<size_msv; ++i){
////            std::cout << msv_after[i] << std::endl;
////        }

//        package_bearing::Message_bearing bearing2;
//        bearing2.ParseFromArray(msv_after, size_msv);

//        std::cout << "Read from Qfile ->bearing2.bearing_name() : " << bearing2.bearing_name() << std::endl;
//        std::cout << "Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << bearing2.bearing_diameter_outer_race() << std::endl;

//    //####################################################################


        //8888888888 V variant Vector 8888888888888

//        std::string bearing_message_str = bearing.SerializeAsString();
//        QVector <std::string> vec_qv;
//        vec_qv.append(bearing_message_str);

//        package_bearing::Message_bearing bearing2;
//        bearing2.ParseFromString(vec_qv[0]);
//        std::cout << "Read from Qfile ->bearing2.bearing_name() : " << bearing2.bearing_name() << std::endl;
//        std::cout << "Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << bearing2.bearing_diameter_outer_race() << std::endl;

        //88888888888888888888888888888888888888888

        //()()()()()() V variant QByte Array  <-> std::string   ()()()()()()()()()()()()()
        //Serialize protobuf
//        QByteArray dataQ;
//        QDataStream streamQ(dataQ);
//        streamQ << bearing;
//        return;

        std::string bearing_message_str = bearing.SerializeAsString();
        std::cout << "bearing_message_str : " << bearing_message_str << std::endl;

        //rewrite string in QByteArray
        QByteArray dataQByteArr_before(bearing_message_str.data(), int(bearing_message_str.size()));



//        QByteArray dataQByteArr_before;
//                QDataStream stream_dataQByteArr_before(&dataQByteArr_before, QIODevice::ReadWrite);
//                //        stream3 << (int32_t)100;
//                //write value of massive to container through stream
//                for(quint32 i=0; i<bearing_message_str.size(); ++i){
//                    stream_dataQByteArr_before << bearing_message_str[i];
//                }

        QString filename = "/home/dev/Desktop/serial_pb";

        QFile *file_before = new QFile(filename);
            if(!file_before->open(QFile::WriteOnly | QFile::Truncate)){
                qDebug() << " Could not open file for writing";
            }

            system("sudo chmod 777 /home/dev/Desktop/serial_pb");

            QDataStream stream_in_file(file_before);
            stream_in_file << dataQByteArr_before;
            qDebug() << " file was written";
            file_before->close();
        delete file_before;

        qDebug() << " ----test---";

        //---after


        QFile *file_after = new QFile(filename);
            if(!file_after->open(QFile::ReadWrite)){
                qDebug() << " Could not open file for writing";
            }
            QDataStream stream_from_file(file_after);
            QByteArray dataQByteArr_after;
            stream_from_file >> dataQByteArr_after;
            qDebug() << " file was read";
            file_after->close();
        delete file_after;

        std::string str_bearing_after;
        str_bearing_after = dataQByteArr_after.toStdString();
        //            QDataStream stream_dataQByteArr_after(&dataQByteArr_after, QIODevice::ReadWrite);
        //        stream2 >> cnt; //100
        //write value from container to through stream
        //            for(qint32 i=0; i<bearing_message_str.size(); ++i){
        ////                stream_dataQByteArr_after >> ;
        //                str_bearing += dataQByteArr_after[i];
        //            }

        package_bearing::Message_bearing bearing2;

        bearing2.ParseFromString(str_bearing_after);

        std::cout << "Read from Qfile ->bearing2.bearing_name() : " << bearing2.bearing_name() << std::endl;
        std::cout << "Read from Qfile ->bearing2.bearing_diameter_outer_race() : " << bearing2.bearing_diameter_outer_race() << std::endl;

        //()()()()()()()()()()()()()()()()()()()

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
