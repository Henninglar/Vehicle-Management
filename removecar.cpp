#include "removecar.h"
#include "ui_removecar.h"

removecar::removecar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecar)
{
    ui->setupUi(this);
    this->setWindowTitle("Remove car");
   ui->regnr->setPlaceholderText("ZZ13053");
}


removecar::~removecar()
{
    delete ui;
}

void removecar::on_pushButton_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/henni/OneDrive/Skrivebord/Exam-v22/Exam-v22/database.db");

    mydb.open();


    QSqlQuery qry;

    qry.prepare("DELETE FROM cars WHERE regnr=(:regnr)");

    QString regnr = ui->regnr->text();

    qry.bindValue(":regnr", regnr);
    if(qry.exec()){
        QMessageBox::about(this,"Sucess", "Data inserted");
    }else {
         QMessageBox::about(this,"Error", "Failed insert");
    }

    close();



}

