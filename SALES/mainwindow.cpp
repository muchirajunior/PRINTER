#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>
#include  <QPaintDevice>
#include <QPainter>
#include <QIntValidator>
#include <QDateTime>
#include <QTextDocument>
#include <QDate>
#include <QTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->lineEdit->setValidator( new QIntValidator(0,10000000,this));
     timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(mytime()));
    connect(timer,SIGNAL(timeout()),this,SLOT(mydate()));
    timer->start(1000);

}

void  MainWindow::mytime()
{
    QTime katime=QTime::currentTime();
    QString time=katime.toString("hh : mm : ss");
    QString mytime =katime.toString("h:mm:ss ap");
    ui->label_4->setText(mytime);

}

 void MainWindow::mydate()
{
    QDate kadate=QDate::currentDate();
    QString date=kadate.toString();
    ui->label_3->setText(date);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  on_lineEdit_editingFinished();
}


void MainWindow::on_lineEdit_editingFinished()
{
    QString cash=ui->lineEdit->text();
    if (cash !=""){
    ui->lineEdit->clear();
    QPrinter printer;
    QTime katime=QTime::currentTime();
    QString time=katime.toString("h:mm:ss ap");
    QDate kadate=QDate::currentDate();
     QString date=kadate.toString();
    QString reciept ="BUTCHER MEAT SALES  <br> \t sales reciept <br>"
                     "================<br> amount paid :"+cash+"\n <br><br>At : "+time+"\n<br>"+date+"<br><br>"
                     "================<br>thankyou for buying\n<br> served by: MUCHIRA JUNIOR";
    QPainter painter;
    printer.setPrinterName("your printer");
    QPrintDialog dialog(&printer,this);
     QTextDocument doc;
     doc.setHtml(reciept);
    if (dialog.exec() == QDialog::Rejected) return;
    doc.print(&printer);


    }

}
