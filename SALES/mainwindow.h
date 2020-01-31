#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:
    void mytime();
    void mydate();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_actionprint_triggered();

private:
    Ui::MainWindow *ui;
     QTimer *timer;
};

#endif // MAINWINDOW_H
