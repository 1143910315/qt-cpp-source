#ifndef URLSVIEW_H
#define URLSVIEW_H

#include <QDialog>
#include <QMap>
#include <QPushButton>
#include <QUrl>

namespace Ui {
class UrlsView;
}

class UrlsView : public QDialog
{
    Q_OBJECT

public:
    explicit UrlsView(QWidget *parent = nullptr);
    ~UrlsView();
    UrlsView *showUrls(const QList<QUrl> &urls);
    UrlsView *setModal(bool modal);
public slots:
    void openUrl();
private:
    Ui::UrlsView *ui;
    QMap<QPushButton *,QUrl *> *buttonMapToUrl=new QMap<QPushButton *,QUrl *>();
};

#endif // URLSVIEW_H
