#ifndef REMOVECAR_H
#define REMOVECAR_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class removecar;
}

class removecar : public QDialog
{
    Q_OBJECT

public:
    explicit removecar(QWidget *parent = nullptr);
    ~removecar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::removecar *ui;
    QSqlDatabase database;
};

#endif // REMOVECAR_H
