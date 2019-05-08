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
    ui->graphicsView->setBackgroudColor(random.bounded(256),random.bounded(256),random.bounded(256));
    ui->graphicsView_2->setBackgroudColor(random.bounded(256),random.bounded(256),random.bounded(256));
    ui->graphicsView_3->setBackgroudColor(random.bounded(256),random.bounded(256),random.bounded(256));
    ui->graphicsView_4->setBackgroudColor(random.bounded(256),random.bounded(256),random.bounded(256));
    ui->graphicsView_5->setBackgroudColor(random.bounded(256),random.bounded(256),random.bounded(256));
    ui->graphicsView_6->setBackgroudColor(random.bounded(256),random.bounded(256),random.bounded(256));
    ui->graphicsView_7->setBackgroudColor(random.bounded(256),random.bounded(256),random.bounded(256));
    ui->graphicsView_8->setBackgroudColor(random.bounded(256),random.bounded(256),random.bounded(256));
    ui->graphicsView_9->setBackgroudColor(random.bounded(256),random.bounded(256),random.bounded(256));
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

void MainWindow::dropEvent(QDropEvent *event){
    const QMimeData *localMimeData = event->mimeData();
    if(localMimeData->hasColor()){
        QColor color = qvariant_cast<QColor>(localMimeData->colorData());
        int red = color.red();
        int green = color.green();
        int blue = color.blue();
        this->setStyleSheet(QString::asprintf("#MainWindow{background: rgb(%d,%d,%d)}",red,green,blue));
    }
    if(localMimeData->hasImage()){
        QImage img= qvariant_cast<QImage>(localMimeData->imageData());
        pictureView=new PictureView(this);
        pictureView->setModal(false)
                ->showPicture(img)
                ->show();
    }
    if(localMimeData->hasHtml()){
        QString localHtml = localMimeData->html();
        htmlView=new HtmlView(this);
        htmlView->setModal(false)
                ->showHtml(localHtml)
                ->show();
    }
    if(localMimeData->hasUrls()){
        QList<QUrl> localUrls = localMimeData->urls();
        urlsView=new UrlsView();
        urlsView->setModal(false)
                ->showUrls(localUrls)
                ->show();
    }
}


