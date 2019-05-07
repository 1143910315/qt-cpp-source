#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMimeData>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    QString str="=>\n";
    const QMimeData *localMimeData = event->mimeData();
    if(localMimeData->hasHtml()){
        str+="    Html data has been dragged into the window.\n";
    }
    if(localMimeData->hasText()){
        str+="    Text data has been dragged into the window.\n";
    }
    if(localMimeData->hasUrls()){
        str+="    Urls data has been dragged into the window.\n";
    }
    if(localMimeData->hasColor()){
        str+="    Color data has been dragged into the window.\n";
    }
    if(localMimeData->hasImage()){
        str+="    Image data has been dragged into the window.\n";
    }
    str+="    Following is a list of formats.  =>\n";
    QStringList localFormats = localMimeData->formats();
    for (QString format : localFormats) {
        str+="        "+format+"\n";
    }
    ui->textEdit->append(str);
    event->accept();

}




