#include "editcustomer.h"
#include "ui_editcustomer.h"

editcustomer::editcustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcustomer)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit customer");
   ui->selectpersonnr->setPlaceholderText("210102xxxxx");
    ui->newnavn->setPlaceholderText("Henning");
    ui->newalder->setPlaceholderText("20");
}

editcustomer::~editcustomer()
{
    delete ui;
}

void editcustomer::on_editcarbtn_clicked()
{

    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/henni/OneDrive/Skrivebord/Exam-v22/Exam-v22/database.db");

    mydb.open();


    QString navn = ui->newnavn->text();
    QString alder = ui->newalder->text();
    QString personr = ui->selectpersonnr->text();




    QSqlQuery qry;

    qry.prepare("update customers set navn=:navn, alder=:alder where personr=:personr");


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

