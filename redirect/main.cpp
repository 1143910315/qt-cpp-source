#include "mainwindow.h"
#include "base64.h"
#include <QApplication>
#include <QDebug>
#include <QStandardPaths>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    qDebug()<<"writableLocation=============================================QStandardPaths::HomeLocation";
//    qDebug()<<QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
//    qDebug()<<"standardLocations=============================================QStandardPaths::HomeLocation";
//    qDebug()<<QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
//    qDebug()<<"writableLocation=============================================QStandardPaths::AppDataLocation";
//    qDebug()<<QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
//    qDebug()<<"standardLocations=============================================QStandardPaths::AppDataLocation";
//    qDebug()<<QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
//    qDebug()<<"writableLocation=============================================QStandardPaths::AppConfigLocation";
//    qDebug()<<QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
//    qDebug()<<"standardLocations=============================================QStandardPaths::AppConfigLocation";
//    qDebug()<<QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation);
//    qDebug()<<"=============================================";
//    qDebug()<<"test==MD5=======QzpcVXNlcnNcMTE0MzlcQXBwRGF0YVxSb2FtaW5nXERpbmdUYWxrXDUxMjEyMzM0Ml92MlxJbWFnZUZpbGVzXDE1NTc0MDAyNzA1MzBfNTFQXSg5SSRaRkslVVtFSCVQU1g4UE0uanBn====";
//    QByteArray localDecode = Base64::decode("QzpcVXNlcnNcMTE0MzlcQXBwRGF0YVxSb2FtaW5nXERpbmdUYWxrXDUxMjEyMzM0Ml92MlxJbWFnZUZpbGVzXDE1NTc0MDAyNzA1MzBfNTFQXSg5SSRaRkslVVtFSCVQU1g4UE0uanBn");
//    qDebug()<<QString(localDecode);
//    qDebug()<<"=============================================";
    MainWindow w;
    w.show();

    return a.exec();
}
