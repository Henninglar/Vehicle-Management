#include "addcustomer.h"
#include "ui_addcustomer.h"

addcustomer::addcustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcustomer)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Customer");
   ui->navn->setPlaceholderText("Henning");
    ui->alder->setPlaceholderText("20");
    ui->personr->setPlaceholderText("210102xxxxx");
}

addcustomer::~addcustomer()
{
    delete ui;
}





void addcustomer::on_addcustomerBTN_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/henni/OneDrive/Skrivebord/Exam-v22/Exam-v22/database.db");

    mydb.open();


    QString navn = ui->navn->text();
    QString alder = ui->alder->text();
    QString personr = ui->personr->text();



    QSqlQuery qry;

    qry.prepare("INSERT INTO customers (navn, alder, personr) VALUES (:navn, :alder, :personr)");


    qry.bindValue(":navn", navn);
    qry.bindValue(":alder", alder);
    qry.bindValue(":personr", personr);


    if(qry.exec()){
        QMessageBox::about(this,"Sucess", "Data inserted");
    }else {
         QMessageBox::about(this,"Error", "Failed insert");
    }

    close();
}

