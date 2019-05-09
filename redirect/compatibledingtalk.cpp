#include "compatibledingtalk.h"

#include <QByteArray>
#include <QDebug>

CompatibleDingTalk::CompatibleDingTalk(QObject *parent) : QObject(parent)
{

}

void CompatibleDingTalk::transformationDingTalkUrlToFileName(const QString &dingTalkUrl)
{
    qDebug()<<"test========================================";
    QRegExp regexp("http(?:s?)://loc.dingtalk.com/([a-zA-Z0-9\\+\\=]+)");
    int pos=regexp.indexIn(dingTalkUrl);
    QStringList localCapturedTexts = regexp.capturedTexts();
    if(pos!=-1){
        QString source=localCapturedTexts.at(1);
//        QByteArray tempArray = QByteArray::fromBase64();
//        foreach(QString str,localCapturedTexts){
//            qDebug()<<str;
//        }
//        qDebug()<<"mid========================================";
//        qDebug()<<dingTalkUrl.mid(0,pos);
    }
    emit toFileNameReady(dingTalkUrl);
}
