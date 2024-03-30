#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addcar.h"
#include "addcustomer.h"
#include "removecar.h"
#include "removecustomer.h"
#include "editcar.h"
#include "editcustomer.h"
#include "assigncar.h"
#include "unassigncar.h"
#include "seachcar.h"
#include "searchcustomer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Rental car management");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_AC_clicked()
{
    addcar addcar;
    addcar.setModal(true);
    addcar.exec();

}




void MainWindow::on_pushButton_Acus_clicked()
{
    addcustomer addcus;
    addcus.setModal(true);
    addcus.exec();
}


void MainWindow::on_pushButton_RC_clicked()
{
    removecar rc;
    rc.setModal(true);
    rc.exec();

}





void MainWindow::on_removecarbtn_clicked()
{
    removecustomer rcc;
    rcc.setModal(true);
    rcc.exec();


}


void MainWindow::on_editcarbtn_clicked()
{
    editcar editcar;
    editcar.setModal(true);
    editcar.exec();

}


void MainWindow::on_pushButton_6_clicked()
{
    editcustomer editcus;
    editcus.setModal(true);
    editcus.exec();
}


void MainWindow::on_assigncarbtn_clicked()
{
    assigncar assigncar;
    assigncar.setModal(true);
    assigncar.exec();
}


void MainWindow::on_unassigncarbtn_clicked()
{
    unassigncar unas;
    unas.setModal(true);
    unas.exec();
}


void MainWindow::on_searchCar_clicked()
{
    seachcar sc;
    sc.setModal(true);
    sc.exec();
}



void MainWindow::on_pushButton_10_clicked()
{
    searchcustomer sch;
    sch.setModal(true);
    sch.exec();
}

