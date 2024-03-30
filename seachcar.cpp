#include "seachcar.h"
#include "ui_seachcar.h"

seachcar::seachcar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seachcar)
{
    ui->setupUi(this);
    this->setWindowTitle("Search car");
   ui->regnr->setPlaceholderText("zz13053");
}

seachcar::~seachcar()
{
    delete ui;
}

void seachcar::on_searchbtn_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/henni/OneDrive/Skrivebord/Exam-v22/Exam-v22/database.db");

        mydb.open();



    QSqlQueryModel *modal=new QSqlQueryModel();

    QSqlQuery qry;

    qry.prepare("select * from cars WHERE regnr=(:regnr)");

    QString regnr = ui->regnr->text();

    qry.bindValue(":regnr", regnr);

    qry.exec();



    modal->setQuery(qry);
    ui->tableView->setModel(modal);
     }


