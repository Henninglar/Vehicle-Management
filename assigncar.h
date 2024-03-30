#ifndef ASSIGNCAR_H
#define ASSIGNCAR_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQueryModel>

namespace Ui {
class assigncar;
}

class assigncar : public QDialog
{
    Q_OBJECT

public:
    explicit assigncar(QWidget *parent = nullptr);
    ~assigncar();

private slots:
    void on_assigncar_2_clicked();

private:
    Ui::assigncar *ui;
};

#endif // ASSIGNCAR_H
