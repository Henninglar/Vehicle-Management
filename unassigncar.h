#ifndef UNASSIGNCAR_H
#define UNASSIGNCAR_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQueryModel>

namespace Ui {
class unassigncar;
}

class unassigncar : public QDialog
{
    Q_OBJECT

public:
    explicit unassigncar(QWidget *parent = nullptr);
    ~unassigncar();

private slots:
    void on_unassignbtn_clicked();

private:
    Ui::unassigncar *ui;
};

#endif // UNASSIGNCAR_H
