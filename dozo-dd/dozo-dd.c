/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();
    printf("ADC Example, measuring GPIO26\n");

    adc_init();

    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    // Select ADC input 0 (GPIO26)
    adc_select_input(0);
    int hit_count = 0;
    int cycle_count = 0;
    int cycle_count_max = 10;

    while (1) {
        uint16_t result = adc_read();
        if ( result > 427 ) {
            hit_count++;
            if ( hit_count > 2 ) {
                printf("HIT-%d\n", result);
                hit_count = 0;
            }
        }
        cycle_count++;
        if ( cycle_count >= cycle_count_max ) {
            cycle_count = 0;
            hit_count = 0;
        }
    }
}