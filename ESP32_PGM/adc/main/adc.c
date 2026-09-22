#include <stdio.h>
# include "esp_adc/adc_oneshot.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    float adc_voltage;
    adc_oneshot_unit_handle_t handle;//create adc1 handle
    adc_oneshot_unit_init_cfg_t init_config;//declaration of init config
    init_config.unit_id = ADC_UNIT_1;//set adc i  UNIT as output adc
    adc_oneshot_new_unit(&init_config, &handle);//passing init config and handle to adc unit configuration structure
    adc_oneshot_chan_cfg_t config;//declaration of channel configuration structure
    config.atten = ADC_ATTEN_DB_6;//maximum voltage range 0-3.3v can be counted from 0 - 4095
    config.bitwidth = ADC_BITWIDTH_DEFAULT;//set adc bit width as 12 bitd(default)
    adc_oneshot_config_channel(handle, ADC_CHANNEL_6, &config);//passing handle,channel value and configuration settings to channel configuration structure
    while(1)
    {

    int raw =0;//variable to store adc value
    adc_oneshot_read(handle, ADC_CHANNEL_6, &raw);//read adc value from channel 6 and store in raw variable
    printf("ADC Raw Data: %d\n", raw);//print adc value in console   
     adc_voltage=(raw*3.3)/4095;
     printf("ADC VOLTAGE: %.2f V\n",adc_voltage);
    vTaskDelay(pdMS_TO_TICKS(1000));//delay of 1 second
    }


}
