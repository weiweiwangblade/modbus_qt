#ifndef MODBUSWANGWEI_H
#define MODBUSWANGWEI_H

extern "C"
{
#include "modbus.h"
#include "modbus-private.h"
#include "modbus-rtu.h"
#include "modbus-version.h"
#include "modbus-rtu-private.h"
#include "config.h"
#include "errno.h"
}

class register_groups
{
public:

    int start__addr;
    int register_numbers;
    unsigned char *register_value;

    void set_io_status(int addr, int nb)
    {
        this->start__addr = addr;
        this->register_numbers = nb;
        this->register_value = NULL;
    }
};

class modbus_rtu
{
public:
    modbus_rtu(unsigned char id_slave)
    {
        this->slave_id = id_slave;
    }
    ~modbus_rtu();

    int slave_id;
    register_groups *output_value;
    register_groups *output_status;
    register_groups *input_value;
    register_groups *anlog_sample;

    void modbus_setup()
    {
        output_value = new register_groups;
        output_status = new register_groups;
        input_value = new register_groups;
        anlog_sample = new register_groups;
    }

    modbus_t* _modbus_new_rtu(const char *device,
                             int baud, char parity, int data_bit,
                             int stop_bit);
    int _modbus_set_slave(modbus_t *ctx, int slave);
    int _modbus_connect(modbus_t *ctx);
    int _modbus_read_bits(modbus_t *ctx, int addr, int nb, uint8_t *dest);
    int _modbus_write_bites(modbus_t *ctx, int addr, int nb, u_int8_t *src);
};



#endif // MODBUSWANGWEI_H
