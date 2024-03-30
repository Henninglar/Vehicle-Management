#include "removecustomer.h"
#include "ui_removecustomer.h"

removecustomer::removecustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecustomer)
{
    ui->setupUi(this);
    this->setWindowTitle("Remove customer");
   ui->personnr->setPlaceholderText("210102xxxxx");
}

removecustomer::~removecustomer()
{
    delete ui;
}

void removecustomer::on_Removecusbtn_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/henni/OneDrive/Skrivebord/Exam-v22/Exam-v22/database.db");
    mydb.open();


    QString personr = ui->personnr->text();




    QSqlQuery qry;

    qry.prepare("DELETE FROM customers WHERE personr=(:personr)");
    qry.bindValue(":personr", personr);


    if(qry.exec()){
        QMessageBox::about(this,"Sucess", "Data inserted");
    }else {
         QMessageBox::about(this,"Error", "Failed insert");
    }

    close();
}

