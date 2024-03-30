#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_AC_clicked();

    void on_pushButton_Acus_clicked();

    void on_pushButton_RC_clicked();

    void on_removecarbtn_clicked();

    void on_editcarbtn_clicked();

    void on_pushButton_6_clicked();

    void on_assigncarbtn_clicked();

    void on_unassigncarbtn_clicked();

    void on_searchCar_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
