//##############################################################################################//
//##############################################################################################//
#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//##############################################################################################//
//##############################################################################################/3
void FastFire(uint pinNumber1, uint pinNumber2, uint pinNumber3, uint duration, uint gpio_0_start_state, uint gpio_1_start_state, uint gpio_2_start_state);
void SuperFastFire(uint pinNumber1, uint pinNumber2, uint pinNumber3, uint duration, uint gpio_0_start_state, uint gpio_1_start_state, uint gpio_2_start_state);
int UsbInput();
//##############################################################################################//
//##############################################################################################//
int main()
{
    // Initialise I/O
    stdio_init_all();

    // Init LED PIN for to make accessible to the firmware.
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    // Run Main Loop
    while (true)
    {
        UsbInput();
    }
}
//##############################################################################################//
//##############################################################################################//
void FastFire(uint pinNumber1, uint pinNumber2, uint pinNumber3, uint duration, uint gpio_0_start_state, uint gpio_1_start_state, uint gpio_2_start_state)
{
    printf("HIT!!!!!!!!\n");
    if (pinNumber2 == 99)
    {
        // Disable secondary pin support if pinNumber2 is set to 99

        // Init GPIO pin
        gpio_init(pinNumber1);

        // Set Pin direction
        gpio_set_dir(pinNumber1, GPIO_OUT);

        // Pull down single pin
        gpio_put(pinNumber1, 0);
        sleep_ms(1);
        gpio_put(pinNumber1, gpio_0_start_state);
        sleep_ms(duration);
        gpio_put(pinNumber1, 0);
        sleep_ms(1);
    }
    else if (pinNumber3 == 99)
    {
        // Disable secondary pin support if pinNumber2 is set to 99

        // Init GPIO pins
        gpio_init(pinNumber1);
        gpio_init(pinNumber2);

        // Set Pin directions
        gpio_set_dir(pinNumber1, GPIO_OUT);
        gpio_set_dir(pinNumber2, GPIO_OUT);

        // Pull down all pins
        gpio_put(pinNumber1, 0);
        gpio_put(pinNumber2, 0);
        sleep_ms(1);
        gpio_put(pinNumber1, gpio_0_start_state);
        gpio_put(pinNumber2, gpio_1_start_state);
        sleep_ms(duration);
        gpio_put(pinNumber1, 0);
        gpio_put(pinNumber2, 0);
        sleep_ms(1);
    }
    else if (pinNumber3 != 99) {
        // Disable secondary pin support if pinNumber2 is set to 99

        // Init GPIO pins
        gpio_init(pinNumber1);
        gpio_init(pinNumber2);
        gpio_init(pinNumber3);

        // Set Pin directions
        gpio_set_dir(pinNumber1, GPIO_OUT);
        gpio_set_dir(pinNumber2, GPIO_OUT);
        gpio_set_dir(pinNumber3, GPIO_OUT);

        // Pull down all pins
        gpio_put(pinNumber1, 0);
        gpio_put(pinNumber2, 0);
        gpio_put(pinNumber3, 0);
        sleep_ms(1);
        gpio_put(pinNumber1, gpio_0_start_state);
        gpio_put(pinNumber2, gpio_1_start_state);
        gpio_put(pinNumber2, gpio_2_start_state);
        sleep_ms(duration);
        gpio_put(pinNumber1, 0);
        gpio_put(pinNumber2, 0);
        gpio_put(pinNumber3, 0);
        sleep_ms(1);
    }
}

//##############################################################################################//
//##############################################################################################//
void SuperFastFire(uint pinNumber1, uint pinNumber2, uint pinNumber3, uint duration, uint gpio_0_start_state, uint gpio_1_start_state, uint gpio_2_start_state)
{
    if (pinNumber2 == 99)
    {
        // Disable secondary pin support if pinNumber2 is set to 99

        // Init GPIO pin
        gpio_init(pinNumber1);

        // Set Pin direction
        gpio_set_dir(pinNumber1, GPIO_OUT);

        // Pull down single pin
        gpio_put(pinNumber1, 0);
        busy_wait_us_32(1);

        gpio_put(pinNumber1, gpio_0_start_state);
        busy_wait_us_32(1);

        gpio_put(pinNumber1, 0);
        busy_wait_us_32(1);
    }
    else if (pinNumber2 != 99)
    {
        // Disable secondary pin support if pinNumber2 is set to 99

        // Init GPIO pins
        gpio_init(pinNumber1);
        gpio_init(pinNumber2);

        // Set Pin directions
        gpio_set_dir(pinNumber1, GPIO_OUT);
        gpio_set_dir(pinNumber2, GPIO_OUT);

        // Pull down all pins
        gpio_put(pinNumber1, 0);
        gpio_put(pinNumber2, 0);
        busy_wait_us_32(1);
        gpio_put(pinNumber1, gpio_0_start_state);
        gpio_put(pinNumber2, gpio_1_start_state);
        busy_wait_us_32(duration);
        gpio_put(pinNumber1, 0);
        gpio_put(pinNumber2, 0);
        busy_wait_us_32(1);
    }
    else if (pinNumber3 != 99) {
        // Disable secondary pin support if pinNumber2 is set to 99

        // Init GPIO pins
        gpio_init(pinNumber1);
        gpio_init(pinNumber2);
        gpio_init(pinNumber3);

        // Set Pin directions
        gpio_set_dir(pinNumber1, GPIO_OUT);
        gpio_set_dir(pinNumber2, GPIO_OUT);
        gpio_set_dir(pinNumber3, GPIO_OUT);

        // Pull down all pins
        gpio_put(pinNumber1, 0);
        gpio_put(pinNumber2, 0);
        gpio_put(pinNumber3, 0);
        busy_wait_us_32(1);
        gpio_put(pinNumber1, gpio_0_start_state);
        gpio_put(pinNumber2, gpio_1_start_state);
        gpio_put(pinNumber2, gpio_2_start_state);
        busy_wait_us_32(duration);
        gpio_put(pinNumber1, 0);
        gpio_put(pinNumber2, 0);
        gpio_put(pinNumber3, 0);
        busy_wait_us_32(1);
    }
}
//##############################################################################################//
//##############################################################################################//
int UsbInput()
{
    // Get User Input
    // printf("Enter GPIO PIN Number\n");
    //  IMPORTANT!!
    //  The getchar_timeout_us() func was the only input I could get to work.
    //  Don't use anything else for usb input unless you know it works.
    char UsbInput[16];
    sleep_ms(5);

    UsbInput[0] = getchar_timeout_us(0);
    UsbInput[1] = getchar_timeout_us(0);
    UsbInput[2] = getchar_timeout_us(0);
    UsbInput[3] = getchar_timeout_us(0);
    UsbInput[4] = getchar_timeout_us(0);
    UsbInput[5] = getchar_timeout_us(0);
    UsbInput[6] = getchar_timeout_us(0);
    UsbInput[7] = getchar_timeout_us(0);
    UsbInput[8] = getchar_timeout_us(0);
    UsbInput[9] = getchar_timeout_us(0);
    UsbInput[10] = getchar_timeout_us(0);
    UsbInput[11] = getchar_timeout_us(0);
    UsbInput[12] = getchar_timeout_us(0);
    UsbInput[13] = getchar_timeout_us(0);
    UsbInput[14] = getchar_timeout_us(0);
    UsbInput[15] = getchar_timeout_us(0);
    UsbInput[16] = getchar_timeout_us(0);
    UsbInput[17] = getchar_timeout_us(0);

    // Check Stop Char - char that is known at end of string.
    // If missing the string is very likeley Corrupted.
    char start_bit[1] = {UsbInput[0]};
    char gpio_0_number[2] = {UsbInput[1], UsbInput[2]};
    char gpio_1_number[2] = {UsbInput[3], UsbInput[4]};
    char gpio_2_number[2] = {UsbInput[5], UsbInput[6]};
    char gpio_0_start_state[1] = {UsbInput[7]};
    char gpio_1_start_state[1] = {UsbInput[8]};
    char gpio_2_start_state[1] = {UsbInput[9]};
    char duration[4] = {UsbInput[10], UsbInput[11], UsbInput[12], UsbInput[13]};
    char gpioDirection[1] = {UsbInput[14]};
    char time_mode[1] = {UsbInput[15]};
    char program_mode[1] = {UsbInput[16]};
    char stop_bit[1] = {UsbInput[17]};

    //700999911100100047
    uint start_bitInt;
    start_bitInt = atoi(start_bit);    

    // Cast USB input string as uint type 
    uint stop_bitInt;
    stop_bitInt = atoi(stop_bit);
    
    if ( start_bitInt == 7 && stop_bitInt == 7 ) {
    //printf("#########################################################################################################################################################################################################################################################################################################HIT#########################################################################################################################################################################################################################################################################################################n");
    } else if ( start_bitInt == 7 && stop_bitInt != 7 || start_bitInt != 7 && stop_bitInt == 7 ) {
        printf("!!!**Corrupted Input String***!!!\n");
        return 2;
    } else {
        //printf("loop\n");
        return 1;
    }

//for i in {1..5000}; do echo "700999911100100047" > /dev/ttyACM0; sleep 0.01;  done

    // Cast USB input string as uint/gpio type 
    uint selectedgpio_0_number;
    selectedgpio_0_number = atoi(gpio_0_number);

    // Cast USB input string as uint/gpio type 
    uint selectedgpio_1_number;
    selectedgpio_1_number = atoi(gpio_1_number);

    // Cast USB input string as uint/gpio type 
    uint selectedgpio_2_number;
    selectedgpio_2_number = atoi(gpio_2_number);

    // Cast USB input string as uint/gpio type 
    uint selectedgpio_0_start_state;
    selectedgpio_0_start_state = atoi(gpio_0_start_state);

    // Cast USB input string as uint/gpio type 
    uint selectedgpio_1_start_state;
    selectedgpio_1_start_state = atoi(gpio_1_start_state);

    // Cast USB input string as uint/gpio type 
    uint selectedgpio_2_start_state;
    selectedgpio_2_start_state = atoi(gpio_2_start_state);


    // Cast pulse duration input string as uint/gpio type 
    uint pulseDurationInt;
    pulseDurationInt = atoi(duration);

    // Cast time_modeCode input string as uint type 
    uint time_modeCode;
    time_modeCode = atoi(time_mode);

    // Cast pulse duration input string as uint/gpio type 
    uint program_modeCode;
    program_modeCode = atoi(program_mode);

    // Adjust time values based on info decoded from input string.
    uint timeAdjust;
    if (time_modeCode == 1)
    {
        // Adjust to Seconds
        timeAdjust = 1000;
    }
    else if (time_modeCode == 0)
    {
        timeAdjust = 1;
    }
    else
    {
        timeAdjust = 1;
    }

    uint adjustedPulseDuration;
    adjustedPulseDuration = pulseDurationInt * timeAdjust;

    // Cast pin direction input char as uint/gpio type 
    int pinDirection;
    pinDirection = atoi(gpioDirection);
//##############################################################################################//
    // Execute Fuctions based on user specified program mode
    if (program_modeCode == 1)
    {
        // Program Mode 1 Conditional
        printf("Alt Mode selected\n");
    }
    else if (program_modeCode == 0)
    {
        // Program Mode 0 Conditional

        // Perform Action based on selected pin direction.
        if (pinDirection == 0)
        {
            FastFire(selectedgpio_0_number, selectedgpio_1_number, selectedgpio_2_number, adjustedPulseDuration, selectedgpio_0_start_state, selectedgpio_1_start_state, selectedgpio_2_start_state);
        }

        else if (pinDirection == 1)
        {
            //Input Pin Logic
            return 1;
        }
        else
        {
            return 1;
            // Pin direction error conditional
            printf("error! Input direction is incorrect. Direction selected: %d\n", pinDirection);
        }
    }
//##############################################################################################//
    else if (program_modeCode == 2)
    {
            SuperFastFire(selectedgpio_0_number, selectedgpio_1_number, selectedgpio_2_number, adjustedPulseDuration, selectedgpio_0_start_state, selectedgpio_1_start_state, selectedgpio_2_start_state);
    }
//##############################################################################################//
    else if (program_modeCode == 3)
        {
            //Input Pin Logic
            FastFire(selectedgpio_0_number, selectedgpio_1_number, selectedgpio_2_number, adjustedPulseDuration, selectedgpio_0_start_state, selectedgpio_1_start_state, selectedgpio_2_start_state);
            SuperFastFire(selectedgpio_0_number, selectedgpio_1_number, selectedgpio_2_number, adjustedPulseDuration, selectedgpio_0_start_state, selectedgpio_1_start_state, selectedgpio_2_start_state);
        }

//##############################################################################################//
    else if (program_modeCode == 4)
    {
            FastFire(selectedgpio_0_number, selectedgpio_1_number, selectedgpio_2_number, adjustedPulseDuration, selectedgpio_0_start_state, selectedgpio_1_start_state, selectedgpio_2_start_state);
            FastFire(28, 99, 99, 1, selectedgpio_0_start_state, selectedgpio_1_start_state, selectedgpio_2_start_state);
    }
    return 0;
}
//##############################################################################################//
//##############################################################################################//