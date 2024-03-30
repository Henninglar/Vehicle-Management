#ifndef ADDCUSTOMER_H
#define ADDCUSTOMER_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class addcustomer;
}

class addcustomer : public QDialog
{
    Q_OBJECT

public:
    explicit addcustomer(QWidget *parent = nullptr);
    ~addcustomer();

private slots:

    void on_addcustomerBTN_clicked();

private:
    Ui::addcustomer *ui;
};

#endif // ADDCUSTOMER_H
