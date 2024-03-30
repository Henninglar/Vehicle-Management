#ifndef SEACHCAR_H
#define SEACHCAR_H


#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQueryModel>

namespace Ui {
class seachcar;
}

class seachcar : public QDialog
{
    Q_OBJECT

public:
    explicit seachcar(QWidget *parent = nullptr);
    ~seachcar();

private slots:
    void on_searchbtn_clicked();

private:
    Ui::seachcar *ui;
};

#endif // SEACHCAR_H
