#include "urlsview.h"
#include "ui_urlsview.h"

#include <QDesktopServices>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSignalMapper>
#include <QTextEdit>
#include <QUrl>

UrlsView::UrlsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UrlsView)
{
    ui->setupUi(this);
}

UrlsView::~UrlsView()
{
    QList<QUrl *> localValues = buttonMapToUrl->values();
    foreach (QUrl *url, localValues) {
        delete url;
    }
    buttonMapToUrl->clear();
    delete buttonMapToUrl;
    delete ui;
}

UrlsView *UrlsView::showUrls(const QList<QUrl> &urls)
{
    QGridLayout *pLayout = new QGridLayout();
    int row=0;
    foreach (QUrl url, urls) {
        QString localUrl = url.url();
        QTextEdit *pTextEdit = new QTextEdit(this);
        pTextEdit->setText(localUrl);
        QPushButton *pOpenButton = new QPushButton(this);
        pOpenButton->setText("打开此链接");
        QSizePolicy localSizePolicy = pOpenButton->sizePolicy();
        localSizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
        localSizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
        pOpenButton->setSizePolicy(localSizePolicy);
        buttonMapToUrl->insert(pOpenButton,new QUrl(url));
        localSizePolicy = pTextEdit->sizePolicy();
        localSizePolicy.setVerticalPolicy(QSizePolicy::Preferred);
        localSizePolicy.setHorizontalPolicy(QSizePolicy::Preferred);
        pTextEdit->setSizePolicy(localSizePolicy);
        pTextEdit->setAcceptDrops(false);
        connect(pOpenButton, SIGNAL(clicked()), this, SLOT(openUrl()));
        pLayout->addWidget(pTextEdit, row, 0);
        pLayout->addWidget(pOpenButton, row++, 1);
    }
    setLayout(pLayout);
    return this;
}

UrlsView *UrlsView::setModal(bool modal)
{
    QDialog::setModal(modal);
    return this;
}

void UrlsView::openUrl()
{
    QPushButton *localButton=qobject_cast<QPushButton *>(sender());
    QUrl * const localValue = buttonMapToUrl->value(localButton,nullptr);
    if(localValue!=nullptr){
        QDesktopServices::openUrl(*localValue);
    }
}
