#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modbus-wangwei.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_create_clicked()
{
    this->signal_collection = new modbus_rtu(3);
    this->signal_collection->modbus_setup();
    this->cxt = this->signal_collection->_modbus_new_rtu("/dev/ttyUSB0",115200,'N',8,1);
    signal_collection->_modbus_set_slave(this->cxt,signal_collection->slave_id);
    signal_collection->_modbus_connect(this->cxt);
    signal_collection->output_value->start__addr = 2;
    signal_collection->output_value->register_numbers = 5;

}

void MainWindow::on_pushButton_clicked()
{
    modbus_close(this->cxt);
}

void MainWindow::on_read_clicked()
{
    unsigned char data[5] = {0x00};
    signal_collection->_modbus_read_bits(this->cxt,
                                         signal_collection->output_value->start__addr,
                                         signal_collection->output_value->register_numbers,
                                         data);
}
