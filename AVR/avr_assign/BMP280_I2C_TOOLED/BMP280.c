#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "bmp280.h"
#include "i2c.h"
#include "uart.h"

/* BMP280 I2C Address */
#define BMP280_ADDR        0x76

/* BMP280 Registers */
#define BMP280_CHIP_ID     0xD0
#define BMP280_RESET       0xE0
#define BMP280_CTRL_MEAS   0xF4
#define BMP280_CONFIG      0xF5

#define BMP280_PRESS_MSB   0xF7
#define BMP280_TEMP_MSB    0xFA

/* Calibration data starts from 0x88 */
#define BMP280_CALIB_START 0x88


/* =========================================================
   Calibration Variables
   ========================================================= */

/* Temperature calibration coefficients */
static uint16_t dig_T1;
static int16_t  dig_T2;
static int16_t  dig_T3;

/* Pressure calibration coefficients */
static uint16_t dig_P1;
static int16_t  dig_P2;
static int16_t  dig_P3;
static int16_t  dig_P4;
static int16_t  dig_P5;
static int16_t  dig_P6;
static int16_t  dig_P7;
static int16_t  dig_P8;
static int16_t  dig_P9;

/* Used by pressure compensation */
static int32_t t_fine;


/* =========================================================
   Read BMP280 Chip ID
   ========================================================= */

uint8_t bmp280_read_chip_id(void)
{
    uint8_t chip_id;

    /* START */
    i2c_start();

    /* BMP280 address + WRITE */
    i2c_write(BMP280_ADDR << 1);

    /* Register address */
    i2c_write(BMP280_CHIP_ID);

    /* Repeated START */
    i2c_start();

    /* BMP280 address + READ */
    i2c_write((BMP280_ADDR << 1) | 1);

    /* Read one byte and send NACK */
    chip_id = i2c_read_nack();

    /* STOP */
    i2c_stop();

    return chip_id;
}


/* =========================================================
   Initialize BMP280
   ========================================================= */

void bmp280_init(void)
{
    i2c_start();

    /* BMP280 address + WRITE */
    i2c_write(BMP280_ADDR << 1);

    /* CTRL_MEAS register */
    i2c_write(BMP280_CTRL_MEAS);

    /*
       0x4F

       Temperature oversampling = x2
       Pressure oversampling   = x4
       Normal mode
    */
    i2c_write(0x4F);

    i2c_stop();

    _delay_ms(100);
}


/* =========================================================
   Read Calibration Data
   ========================================================= */

void bmp280_read_calibration_data(void)
{
    uint8_t data[24];

    /*
       Calibration registers:
       0x88 to 0x9F
       Total = 24 bytes
    */

    i2c_start();

    /* BMP280 address + WRITE */
    i2c_write(BMP280_ADDR << 1);

    /* Start calibration register */
    i2c_write(BMP280_CALIB_START);

    /* Repeated START */
    i2c_start();

    /* BMP280 address + READ */
    i2c_write((BMP280_ADDR << 1) | 1);

    /* Read first 23 bytes with ACK */
    for (uint8_t i = 0; i < 23; i++)
    {
        data[i] = i2c_read_ack();
    }

    /* Read last byte with NACK */
    data[23] = i2c_read_nack();

    i2c_stop();


    /* =====================================================
       Temperature Calibration Data
       ===================================================== */

    dig_T1 = (uint16_t)data[1] << 8 | data[0];

    dig_T2 = (int16_t)(
                (uint16_t)data[3] << 8 |
                data[2]
             );

    dig_T3 = (int16_t)(
                (uint16_t)data[5] << 8 |
                data[4]
             );


    /* =====================================================
       Pressure Calibration Data
       ===================================================== */

    dig_P1 = (uint16_t)data[7] << 8 | data[6];

    dig_P2 = (int16_t)(
                (uint16_t)data[9] << 8 |
                data[8]
             );

    dig_P3 = (int16_t)(
                (uint16_t)data[11] << 8 |
                data[10]
             );

    dig_P4 = (int16_t)(
                (uint16_t)data[13] << 8 |
                data[12]
             );

    dig_P5 = (int16_t)(
                (uint16_t)data[15] << 8 |
                data[14]
             );

    dig_P6 = (int16_t)(
                (uint16_t)data[17] << 8 |
                data[16]
             );

    dig_P7 = (int16_t)(
                (uint16_t)data[19] << 8 |
                data[18]
             );

    dig_P8 = (int16_t)(
                (uint16_t)data[21] << 8 |
                data[20]
             );

    dig_P9 = (int16_t)(
                (uint16_t)data[23] << 8 |
                data[22]
             );
}


/* =========================================================
   Read Raw Temperature
   ========================================================= */

int32_t bmp280_read_raw_temperature(void)
{
    uint8_t msb;
    uint8_t lsb;
    uint8_t xlsb;

    int32_t raw_temperature;

    i2c_start();

    /* BMP280 address + WRITE */
    i2c_write(BMP280_ADDR << 1);

    /* Temperature MSB register = 0xFA */
    i2c_write(BMP280_TEMP_MSB);

    /* Repeated START */
    i2c_start();

    /* BMP280 address + READ */
    i2c_write((BMP280_ADDR << 1) | 1);

    /* Read 3 bytes */
    msb  = i2c_read_ack();
    lsb  = i2c_read_ack();
    xlsb = i2c_read_nack();

    i2c_stop();


    /*
       BMP280 temperature is 20-bit.

       MSB  -> bits 19:12
       LSB  -> bits 11:4
       XLSB -> bits 3:0
    */

    raw_temperature =
          ((int32_t)msb << 12)
        | ((int32_t)lsb << 4)
        | ((int32_t)xlsb >> 4);

    return raw_temperature;
}


/* =========================================================
   Read Raw Pressure
   ========================================================= */

int32_t bmp280_read_raw_pressure(void)
{
    uint8_t msb;
    uint8_t lsb;
    uint8_t xlsb;

    int32_t raw_pressure;

    i2c_start();

    /* BMP280 address + WRITE */
    i2c_write(BMP280_ADDR << 1);

    /* Pressure MSB register = 0xF7 */
    i2c_write(BMP280_PRESS_MSB);

    /* Repeated START */
    i2c_start();

    /* BMP280 address + READ */
    i2c_write((BMP280_ADDR << 1) | 1);

    /* Read 3 bytes */
    msb  = i2c_read_ack();
    lsb  = i2c_read_ack();
    xlsb = i2c_read_nack();

    i2c_stop();


    /*
       BMP280 pressure is 20-bit.

       MSB  -> bits 19:12
       LSB  -> bits 11:4
       XLSB -> bits 3:0
    */

    raw_pressure =
          ((int32_t)msb << 12)
        | ((int32_t)lsb << 4)
        | ((int32_t)xlsb >> 4);

    return raw_pressure;
}


/* =========================================================
   Temperature Compensation
   =========================================================

   Input:
       adc_T = raw temperature ADC value

   Output:
       Temperature in 0.01 degree Celsius

       Example:
       2534 = 25.34 °C
   ========================================================= */

int32_t bmp280_compensate_temperature(int32_t adc_T)
{
    int32_t var1;
    int32_t var2;
    int32_t temperature;


    /* First calculation */

    var1 =
        ((((adc_T >> 3) -
        ((int32_t)dig_T1 << 1))
        * ((int32_t)dig_T2)) >> 11);


    /* Second calculation */

    var2 =
        (((((adc_T >> 4) -
        ((int32_t)dig_T1)) *
        ((adc_T >> 4) -
        ((int32_t)dig_T1))) >> 12)
        * ((int32_t)dig_T3) >> 14);


    /* t_fine is required for pressure calculation */

    t_fine = var1 + var2;


    /* Temperature in 0.01 °C */

    temperature =
        (t_fine * 5 + 128) >> 8;


    return temperature;
}


/* =========================================================
   Pressure Compensation
   =========================================================

   Input:
       adc_P = raw pressure ADC value

   Output:
       Pressure in Pa
   ========================================================= */

uint32_t bmp280_compensate_pressure(int32_t adc_P)
{
    int64_t var1;
    int64_t var2;
    int64_t pressure;


    var1 = ((int64_t)t_fine) - 128000;


    var2 =
        var1 * var1 * (int64_t)dig_P6;


    var2 =
        var2 +
        ((var1 * (int64_t)dig_P5) << 17);


    var2 =
        var2 +
        (((int64_t)dig_P4) << 35);


    var1 =
        ((var1 * var1 * (int64_t)dig_P3) >> 8)
        +
        ((var1 * (int64_t)dig_P2) << 12);


    var1 =
        ((((int64_t)1 << 47) + var1)
        * ((int64_t)dig_P1)) >> 33;


    /* Avoid division by zero */

    if (var1 == 0)
    {
        return 0;
    }


    pressure =
        (int64_t)1048576 - adc_P;


    pressure =
        (((pressure << 31) - var2) * 3125)
        / var1;


    var1 =
        (((int64_t)dig_P9) *
        ((pressure >> 13) *
        (pressure >> 13))) >> 25;


    var2 =
        (((int64_t)dig_P8) *
        pressure) >> 19;


    pressure =
        ((pressure + var1 + var2) >> 8)
        +
        (((int64_t)dig_P7) << 4);


    /*
       Convert to Pascal.

       Internal result is scaled by 256,
       therefore divide by 256.
    */

    return (uint32_t)(pressure / 256);
}