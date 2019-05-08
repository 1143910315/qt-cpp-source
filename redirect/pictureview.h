#ifndef PICTUREVIEW_H
#define PICTUREVIEW_H

#include <QDialog>

namespace Ui {
class PictureView;
}

class PictureView : public QDialog
{
    Q_OBJECT

public:
    explicit PictureView(QWidget *parent = nullptr);
    ~PictureView();
    PictureView *showPicture(const QImage &image);
    PictureView *setModal(bool modal);
private:
    Ui::PictureView *ui;
};

#endif // PICTUREVIEW_H
