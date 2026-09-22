#ifndef BMP280_H
#define BMP280_H

#include <stdint.h>

uint8_t bmp280_read_chip_id(void);

void bmp280_init(void);

void bmp280_read_calibration_data(void);

int32_t bmp280_read_raw_temperature(void);

int32_t bmp280_read_raw_pressure(void);

int32_t bmp280_compensate_temperature(int32_t adc_T);

uint32_t bmp280_compensate_pressure(int32_t adc_P);

#endif