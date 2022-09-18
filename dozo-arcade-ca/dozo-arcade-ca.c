//##############################################################################################//
//##############################################################################################//
#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//##############################################################################################//
//##############################################################################################//
int main()
{
    // Initialise I/O
    stdio_init_all();
    // Run Main Loop
    //set_sys_clock_khz(133000, true);

    while (true)
    {
        const uint pulse_input_pin = 16;
        const uint nc_output_pin = 22;
        const uint no_output_pin = 18;

        gpio_init(pulse_input_pin);
        gpio_init(nc_output_pin);
        gpio_init(no_output_pin);

        // Set Pin direction
        gpio_set_dir(pulse_input_pin, GPIO_IN);
        gpio_set_dir(nc_output_pin, GPIO_OUT);
        gpio_set_dir(no_output_pin, GPIO_OUT);

        uint pulse_value = gpio_get(pulse_input_pin);
        
        if (pulse_value != 0 ) {
            continue;
        } else if (pulse_value == 0 ) {
            printf("miss-%d-%d\n", gpio_get(pulse_input_pin), gpio_get_out_level(pulse_input_pin));
            for (size_t i = 0; i < 10; i++) {
                gpio_put(nc_output_pin, 1);
                gpio_put(no_output_pin, 0);
                sleep_ms(100);
                gpio_put(nc_output_pin, 0);
                sleep_ms(100);
            }
        }
    }
}
//##############################################################################################//
//##############################################################################################//