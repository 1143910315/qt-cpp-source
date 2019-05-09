#ifndef HTMLVIEW_H
#define HTMLVIEW_H

#include "compatibledingtalk.h"

#include <QDialog>
#include <QThread>

namespace Ui {
class HtmlView;
}

class HtmlView : public QDialog
{
    Q_OBJECT

public:
    explicit HtmlView(QWidget *parent = nullptr);
    ~HtmlView();
    HtmlView *showHtml(const QString &html);
    HtmlView *setModal(bool modal);
public slots:
    void change();
    void appendText(const QString &str);
signals:
    void dealDingTalkUrl(const QString &);
private:
    Ui::HtmlView *ui;
    int status=0;
    QThread thread;
    CompatibleDingTalk *compatibleDingTalk=new CompatibleDingTalk;
};

#endif // HTMLVIEW_H
