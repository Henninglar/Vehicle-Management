#ifndef ADDCAR_H
#define ADDCAR_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>


namespace Ui {
class addcar;
}

class addcar : public QDialog
{
    Q_OBJECT

public:
    explicit addcar(QWidget *parent = nullptr);
    ~addcar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addcar *ui;
    QSqlDatabase database;
};

#endif // ADDCAR_H
