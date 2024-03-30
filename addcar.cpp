#include "addcar.h"
#include "ui_addcar.h"
#include <iostream>
#include<QDebug>
#include<QMessageBox>

addcar::addcar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcar)
{
    ui->setupUi(this);
     this->setWindowTitle("Add car");
    ui->Regnr->setPlaceholderText("ZZ13053");
     ui->Merke->setPlaceholderText("BMW");
     ui->Aar->setPlaceholderText("2010");

}





addcar::~addcar()
{
    delete ui;
}



void addcar::on_pushButton_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/henni/OneDrive/Skrivebord/Exam-v22/Exam-v22/database.db");

    mydb.open();

    QString regnr = ui->Regnr->text();
    QString merke = ui->Merke->text();
    QString aar = ui->Aar->text();



    QSqlQuery qry;

    qry.prepare("INSERT INTO cars (regnr, merke, aar) VALUES (:regnr, :merke, :aar)");


    qry.bindValue(":regnr", regnr);
    qry.bindValue(":merke", merke);
    qry.bindValue(":aar", aar);


    if(qry.exec()){
        QMessageBox::about(this,"Sucess", "Data inserted");
    }else {
         QMessageBox::about(this,"Error", "Failed insert");
    }

    close();
}

