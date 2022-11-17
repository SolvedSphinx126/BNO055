#include <stdio.h>
#include "BNO055.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/dma.h"
#include "hardware/pio.h"



// I2C defines
// This example will use I2C0 on GPIO8 (SDA) and GPIO9 (SCL) running at 400KHz.
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define I2C_PORT i2c0
#define I2C_SDA 8
#define I2C_SCL 9



int main()
{
    stdio_init_all();

    // I2C Initialisation. Using it at 400Khz.
    i2c_init(I2C_PORT, 400*1000);
    
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    i2c_inst_t *i2c = i2c0;

    uint8_t data[8];

    reg_1ead(i2c, BNO055_ADDR_LOW, CHIP_ID_ADDR, data, 1);
    if (data[0] != DEV_ID) {
        printf("ERROR: Could not get chip id at 0x%x...\n", CHIP_ID_ADDR);
        //while (true);
    }
    else
    {
        printf("Recieved the value 0x%x! for the chip id\n", data[0]);
    }

    reg_1ead(i2c, BNO055_ADDR_LOW, ACC_ID_ADDR, data, 1);
    if (data[0] != ACC_ID) {
        printf("ERROR: Could not get acc id at 0x%x...\n", ACC_ID_ADDR);
        //while (true);
    }
    else
    {
        printf("Recieved the value 0x%x! for the acc id\n", data[0]);
    }

    reg_1ead(i2c, BNO055_ADDR_LOW, MAG_ID_ADDR, data, 1);
    if (data[0] != MAG_ID) {
        printf("ERROR: Could not get mag id at 0x%x...\n", MAG_ID_ADDR);
        //while (true);
    }
    else
    {
        printf("Recieved the value 0x%x! for the mag id\n", data[0]);
    }

    reg_1ead(i2c, BNO055_ADDR_LOW, GYRO_ID_ADDR, data, 1);
    if (data[0] != GYRO_ID) {
        printf("ERROR: Could not get gyro id at 0x%x...\n", CHIP_ID_ADDR);
        //while (true);
    }
    else
    {
        printf("Recieved the value 0x%x! for the gyro id\n", data[0]);
    }

    puts("Hello, world!");

    return 0;
}
