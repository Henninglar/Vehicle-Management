#ifndef REMOVECUSTOMER_H
#define REMOVECUSTOMER_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class removecustomer;
}

class removecustomer : public QDialog
{
    Q_OBJECT

public:
    explicit removecustomer(QWidget *parent = nullptr);
    ~removecustomer();

private slots:
    void on_Removecusbtn_clicked();

private:
    Ui::removecustomer *ui;
};

#endif // REMOVECUSTOMER_H
