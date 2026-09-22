#include"BMP280.h"
#include"i2c.h"
#include"oled.h"
#include"uart.h"
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
    uint8_t chip_id;
    int32_t raw_temperature, raw_pressure;
    int32_t temp_integer, temp_decimal;
    int32_t pressure_integer, pressure_decimal;
    int32_t temp_absolute;
    
    //initialize i2c, bmp280, oled and uart
    i2c_init();
    bmp280_init();
    oled_init();
    UART_Init();
    //read bmp280 chip id and display it on uart and oled
    chip_id =bmp280_read_chip_id();
    uart_clear();
     UART_TxString("Chip ID: ");
    UART_TxHex(chip_id);
    UART_TxString("\r\n");
    oled_set_cursor(0,0);
    //display bmp280 sensor on oled
    oled_print("BMP280 Sensor");
    _delay_ms(2000);
    oled_set_cursor(1,0);
    //display chip id on oled
    oled_print("Chip ID: ");
    oled_print_uint8(chip_id);
     //temperature and pressure calibration data it is read only once and stored in static variables for later use
     bmp280_read_calibration_data();

    while(1)
    {
        
       //read bmp280 raw data

        raw_temperature = bmp280_read_raw_temperature();
        raw_pressure = bmp280_read_raw_pressure();
        UART_TxString("Raw Temperature: ");
        UART_TxNumber(raw_temperature);
        UART_TxString("\r\n");
        UART_TxString("Raw Pressure: ");
        UART_TxNumber(raw_pressure);
        UART_TxString("\r\n");
       
        
        //temperature and pressure compensation
       
          int32_t temperature = bmp280_compensate_temperature(raw_temperature);
          uint32_t pressure = bmp280_compensate_pressure(raw_pressure);
          //
          if(temperature < 0)
          {
            temp_absolute = -temperature;
              oled_set_cursor(2,0);
              oled_print("Temperature: -");
              
              UART_TxString("Temperature: -");
              UART_TxNumber(temp_absolute);
              UART_TxString("\r\n");
          }
          else
          {
            temp_absolute = temperature;
              UART_TxString("Temperature: ");
              UART_TxNumber(temp_absolute);
              UART_TxString("\r\n");
              oled_set_cursor(2,0);
              oled_print("Temperature: ");
              
          }
          //display temperature in celsius with 2 decimal places, temperature is in hundredths of a degree celsius, so divide by 100 to get degrees celsius
          temp_integer = temp_absolute / 100;
          temp_decimal = temp_absolute % 100;
          //always display 2 decimal places for temperature, if temp_decimal is less than 10, add a leading zero
          if(temp_decimal < 10)
          {
              
              oled_print_uint32(temp_integer);
              oled_print(".");
              oled_print_uint32(0);
              oled_print_uint32(temp_decimal);
              oled_print(" C");
          }
          else
          {
              
              oled_print_uint32(temp_integer);
              oled_print(".");
              oled_print_uint32(temp_decimal);
              oled_print(" C");
          }
          //pressure display in hPa, pressure is in Pa, so divide by 100 to get hPa
          pressure_integer = pressure / 100;
          pressure_decimal = pressure % 100;
          //always display 2 decimal places for pressure, if pressure_decimal is less than 10, add a leading zero
            if(pressure_decimal < 10)
              {
                oled_set_cursor(4,0);
                oled_print("Pressure: ");
                oled_print_uint32(pressure_integer);
                oled_print(".");
                oled_print_uint32(0);
                oled_print_uint32(pressure_decimal);
                oled_print(" hPa");
              }
            else
              {
                oled_set_cursor(4,0);
                oled_print("Pressure: ");
                oled_print_uint32(pressure_integer);
                oled_print(".");
                oled_print_uint32(pressure_decimal);
                oled_print(" hPa");
              }
        _delay_ms(2000);
    }
}