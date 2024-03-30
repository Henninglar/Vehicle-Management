#ifndef EDITCAR_H
#define EDITCAR_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>


namespace Ui {
class editcar;
}

class editcar : public QDialog
{
    Q_OBJECT

public:
    explicit editcar(QWidget *parent = nullptr);
    ~editcar();

private slots:
    void on_editcarbtn_clicked();

private:
    Ui::editcar *ui;
};

#endif // EDITCAR_H
