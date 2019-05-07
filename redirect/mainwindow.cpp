#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMimeData>
#include <QRandomGenerator>
#include <QStyle>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRandomGenerator random=QRandomGenerator::securelySeeded();
    ui->graphicsView->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",random.bounded(256),random.bounded(256),random.bounded(256)));
    ui->graphicsView_2->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",random.bounded(256),random.bounded(256),random.bounded(256)));
    ui->graphicsView_3->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",random.bounded(256),random.bounded(256),random.bounded(256)));
    ui->graphicsView_4->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",random.bounded(256),random.bounded(256),random.bounded(256)));
    ui->graphicsView_5->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",random.bounded(256),random.bounded(256),random.bounded(256)));
    ui->graphicsView_6->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",random.bounded(256),random.bounded(256),random.bounded(256)));
    ui->graphicsView_7->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",random.bounded(256),random.bounded(256),random.bounded(256)));
    ui->graphicsView_8->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",random.bounded(256),random.bounded(256),random.bounded(256)));
    ui->graphicsView_9->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",random.bounded(256),random.bounded(256),random.bounded(256)));
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



