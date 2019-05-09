#ifndef COMPATIBLEDINGTALK_H
#define COMPATIBLEDINGTALK_H

#include <QObject>

class CompatibleDingTalk : public QObject
{
    Q_OBJECT
public:
    explicit CompatibleDingTalk(QObject *parent = nullptr);

signals:
    void toFileNameReady(const QString &result);
public slots:
    void transformationDingTalkUrlToFileName(const QString &dingTalkUrl);
};

#endif // COMPATIBLEDINGTALK_H
