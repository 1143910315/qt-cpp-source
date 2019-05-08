#include "pictureview.h"
#include "ui_pictureview.h"

#include <QPixmap>

PictureView::PictureView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PictureView)
{
    ui->setupUi(this);
}

PictureView::~PictureView()
{
    delete ui;
}

PictureView *PictureView::showPicture(const QImage &image)
{
    ui->label->setPixmap(QPixmap::fromImage(image));
    return this;
}

PictureView *PictureView::setModal(bool modal)
{
    QDialog::setModal(modal);
    return this;
}

