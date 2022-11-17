#ifndef BNO055_C
#define BNO055_C
#include "hardware/i2c.h"
#include "pico/stdlib.h"

// Chip address
static const uint8_t BNO055_ADDR_LOW = 0x28;
static const uint8_t BNO055_ADDR_HIGH = 0x28;

// Registers
static const uint8_t CHIP_ID_ADDR = 0x00;
static const uint8_t ACC_ID_ADDR = 0x01;
static const uint8_t MAG_ID_ADDR = 0x02;
static const uint8_t GYRO_ID_ADDR = 0x03;

// Constants
static const uint8_t DEV_ID = 0xA0;
static const uint8_t ACC_ID = 0xFB;
static const uint8_t MAG_ID = 0x32;
static const uint8_t GYRO_ID = 0x0F;

int reg_w1rite(i2c_inst_t *i2c, const uint addr, const uint8_t reg, uint8_t *buf,const uint8_t nbytes);
int reg_1ead(i2c_inst_t *i2c, const uint addr, const uint8_t reg, uint8_t *buf, const uint8_t nbytes);


#endif