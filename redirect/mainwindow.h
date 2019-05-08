#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDragEnterEvent>
#include <QMainWindow>
#include <pictureview.h>
#include <htmlview.h>
#include <urlsview.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
private:
    Ui::MainWindow *ui;
    PictureView *pictureView;
    HtmlView *htmlView;
    UrlsView *urlsView;
};

#endif // MAINWINDOW_H
