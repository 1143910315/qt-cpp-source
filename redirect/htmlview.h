#ifndef HTMLVIEW_H
#define HTMLVIEW_H

#include <QDialog>

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
private:
    Ui::HtmlView *ui;
    int status=0;
};

#endif // HTMLVIEW_H
