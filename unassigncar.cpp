#include "unassigncar.h"
#include "ui_unassigncar.h"

unassigncar::unassigncar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unassigncar)
{
    ui->setupUi(this);
    this->setWindowTitle("Unassign car");
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
     ui->car->setModel(modal);
     custmodal->setQuery(qry2);
     ui->customer->setModel(custmodal);
}

unassigncar::~unassigncar()
{
    delete ui;
}


void unassigncar::on_unassignbtn_clicked()
{
    QString regnr=ui->car->currentText();
    QString customer=ui->customer->currentText();

        QSqlQuery qry;

        qry.prepare("DELETE FROM rentals WHERE regnr=(:regnr) AND personr=(:personr)");
        qry.bindValue(":regnr", regnr);
        qry.bindValue(":personr", customer);

        if(qry.exec()){
            QMessageBox::about(this,"Sucess", "Data inserted");
        }else {
             QMessageBox::about(this,"Error", "Failed insert");
        }

        close();
}

