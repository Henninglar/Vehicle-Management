#ifndef SEARCHCUSTOMER_H
#define SEARCHCUSTOMER_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQueryModel>


namespace Ui {
class searchcustomer;
}

class searchcustomer : public QDialog
{
    Q_OBJECT

public:
    explicit searchcustomer(QWidget *parent = nullptr);
    ~searchcustomer();

private slots:
    void on_searchbtn_clicked();

private:
    Ui::searchcustomer *ui;
};

#endif // SEARCHCUSTOMER_H
