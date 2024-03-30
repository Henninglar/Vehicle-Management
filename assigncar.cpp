#include "assigncar.h"
#include "ui_assigncar.h"

assigncar::assigncar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assigncar)

{
    ui->setupUi(this);
    this->setWindowTitle("Assign car");
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/henni/OneDrive/Skrivebord/Exam-v22/Exam-v22/database.db");
    mydb.open();

    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQueryModel *custmodal=new QSqlQueryModel();
    QSqlQuery qry;
    QSqlQuery qry2;

     qry.prepare("Select regnr from cars");
     qry.exec();
     qry2.prepare("Select personr from customers");
     qry2.exec();

     modal->setQuery(qry);
     ui->car_assignbox->setModel(modal);
     custmodal->setQuery(qry2);
     ui->customerbox->setModel(custmodal);


}

assigncar::~assigncar()
{
    delete ui;
}

void assigncar::on_assigncar_2_clicked()
{

QString regnr=ui->car_assignbox->currentText();
QString customer=ui->customerbox->currentText();

    QSqlQuery qry;
    qry.prepare("INSERT INTO rentals (personr, regnr) VALUES (:personr, :regnr)");
    qry.bindValue(":regnr", regnr);
    qry.bindValue(":personr", customer);

    if(qry.exec()){
        QMessageBox::about(this,"Sucess", "Data inserted");
    }else {
         QMessageBox::about(this,"Error", "Failed insert");
    }

    close();
}

