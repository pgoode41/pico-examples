//##############################################################################################//
//##############################################################################################//
#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//##############################################################################################//
//##############################################################################################//
void machine_credit_signal(uint nc_output_pin, uint no_output_pin);
int main()
{
    // Initialise I/O
    stdio_init_all();
    // Run Main Loop
    //set_sys_clock_khz(133000, true);
    int count =0;

    while (true)
    {
        const uint free_button_input_pin = 16;
        const uint card_reader_pulse_input_pin = 17;
        const uint nc_output_pin = 20;
        const uint no_output_pin = 21;

        gpio_init(free_button_input_pin);
        gpio_init(card_reader_pulse_input_pin);
        gpio_init(nc_output_pin);
        gpio_init(no_output_pin);

        // Set Pin direction
        gpio_set_dir(free_button_input_pin, GPIO_IN);
        gpio_set_dir(card_reader_pulse_input_pin, GPIO_IN);
        gpio_set_dir(nc_output_pin, GPIO_OUT);
        gpio_set_dir(no_output_pin, GPIO_OUT);

        uint free_button_value = gpio_get(free_button_input_pin);
        uint card_reader_value = gpio_get(card_reader_pulse_input_pin);
        
        if ( card_reader_value == 1 && free_button_value == 0) {
            printf("!###START-FREE-BUTTON-CREDIT-CYCLE###!\n");
            printf("free_button_input-%d-%d-%d\n", gpio_get(card_reader_pulse_input_pin), gpio_get_out_level(card_reader_pulse_input_pin), count);
            count++;
            machine_credit_signal(nc_output_pin, no_output_pin);
            printf("!###END-FREE-BUTTON-CREDIT-CYCLE###!\n");
        } else if ( free_button_value == 1 && card_reader_value == 0 ) {
            printf("!###START-FREE-BUTTON-CREDIT-CYCLE###!\n");
            printf("card_reader_input-%d-%d-%d\n", gpio_get(free_button_input_pin), gpio_get_out_level(free_button_input_pin), count);
            count++;
            machine_credit_signal(nc_output_pin, no_output_pin);
            printf("!###END-FREE-BUTTON-CREDIT-CYCLE###!\n");
        } else {
            continue;
        }
    }
}
//##############################################################################################//
//##############################################################################################//
void machine_credit_signal(uint nc_output_pin, uint no_output_pin) {
    for (size_t i = 0; i < 2; i++) {
        gpio_put(nc_output_pin, 0);
        gpio_put(no_output_pin, 0);
        sleep_ms(100);
        gpio_put(nc_output_pin, 1);
        gpio_put(no_output_pin, 1);
        sleep_ms(100);
    }
}