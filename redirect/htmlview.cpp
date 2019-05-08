#include "htmlview.h"
#include "ui_htmlview.h"

HtmlView::HtmlView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HtmlView)
{
    ui->setupUi(this);
    ui->textEdit->hide();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(change()));
}

HtmlView::~HtmlView()
{
    delete ui;
}

HtmlView *HtmlView::showHtml(const QString &html)
{
    ui->textBrowser->setHtml(html);
    ui->textEdit->setPlainText(html);
    status=status==0?1:0;
    change();
    return this;
}

HtmlView *HtmlView::setModal(bool modal)
{
    QDialog::setModal(modal);
    return this;
}

void HtmlView::change()
{
    switch (status) {
    case 0:
        ui->textEdit->show();
        ui->textBrowser->hide();
        break;
    case 1:
        ui->textEdit->hide();
        ui->textBrowser->show();
        break;
    }
    status=status==0?1:0;
}
