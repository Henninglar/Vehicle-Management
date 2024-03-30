#ifndef EDITCUSTOMER_H
#define EDITCUSTOMER_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class editcustomer;
}

class editcustomer : public QDialog
{
    Q_OBJECT

public:
    explicit editcustomer(QWidget *parent = nullptr);
    ~editcustomer();

private slots:
    void on_editcarbtn_clicked();

private:
    Ui::editcustomer *ui;
};

#endif // EDITCUSTOMER_H
