#include "searchcustomer.h"
#include "ui_searchcustomer.h"

searchcustomer::searchcustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchcustomer)
{
    ui->setupUi(this);
    this->setWindowTitle("Search customer");
   ui->name->setPlaceholderText("Alex");
}

searchcustomer::~searchcustomer()
{
    delete ui;
}

void searchcustomer::on_searchbtn_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/henni/OneDrive/Skrivebord/Exam-v22/Exam-v22/database.db");

        mydb.open();



    QSqlQueryModel *modal=new QSqlQueryModel();

    QSqlQuery qry;

    qry.prepare("select * from customers WHERE navn=(:name)");

    QString name = ui->name->text();

    qry.bindValue(":name", name);

    qry.exec();



    modal->setQuery(qry);
    ui->tableView->setModel(modal);
}

