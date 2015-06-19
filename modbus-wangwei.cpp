
#include "modbus-wangwei.h"

 int modbus_rtu::_modbus_set_slave(modbus_t *ctx, int slave)
{
    return modbus_set_slave(ctx, slave);
}

 int modbus_rtu::_modbus_connect(modbus_t *ctx)
 {
    return modbus_connect(ctx);
 }

 int modbus_rtu::_modbus_read_bits(modbus_t *ctx, int addr, int nb, uint8_t *dest)
 {
    return modbus_read_bits(ctx, addr, nb, dest);
 }

int modbus_rtu::_modbus_write_bites(modbus_t *ctx, int addr, int nb, u_int8_t *src)
{
    return modbus_write_bits(ctx, addr, nb, src);
}

modbus_t* modbus_rtu::_modbus_new_rtu(const char *device,
                         int baud, char parity, int data_bit,
                         int stop_bit)
{
    return modbus_new_rtu(device,baud,parity,data_bit,stop_bit);
}
