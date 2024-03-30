#include "editcar.h"
#include "ui_editcar.h"

editcar::editcar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcar)
{
    ui->setupUi(this);
     this->setWindowTitle("Edit car");
    ui->selectregnr->setPlaceholderText("Registration Number");
     ui->newmerke->setPlaceholderText("BMW");
     ui->newaar->setPlaceholderText("2010");
}

editcar::~editcar()
{
    delete ui;
}

void editcar::on_editcarbtn_clicked()
{

    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/henni/OneDrive/Skrivebord/Exam-v22/Exam-v22/database.db");

        mydb.open();


    QString regnr2edit = ui->selectregnr->text();
    QString merke = ui->newmerke->text();
    QString aar = ui->newaar->text();



    QSqlQuery qry;

    qry.prepare("update cars set merke=:merke, aar=:aar where regnr=:regnr2edit");


    qry.bindValue(":regnr2edit", regnr2edit);
    qry.bindValue(":merke", merke);
    qry.bindValue(":aar", aar);


    if(qry.exec()){
        QMessageBox::about(this,"Sucess", "Data inserted");
    }else {
         QMessageBox::about(this,"Error", "Failed insert");
    }
    close();
}

