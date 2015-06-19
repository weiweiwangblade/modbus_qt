#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modbus-wangwei.h"

extern "C"
{
#include "modbus.h"
#include "modbus-private.h"
#include "modbus-rtu.h"
#include "modbus-version.h"
#include "modbus-rtu-private.h"
#include "config.h"
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_create_clicked();

    void on_pushButton_clicked();

    void on_read_clicked();

private:
    Ui::MainWindow *ui;
    modbus_t *cxt;
    modbus_rtu *signal_collection;
};

#endif // MAINWINDOW_H
