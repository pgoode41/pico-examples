add_executable(dozo-dd
        dozo-dd.c
        )

# pull in common dependencies
target_link_libraries(dozo-dd pico_stdlib hardware_adc)

# create map/bin/hex file etc.
pico_add_extra_outputs(dozo-dd)

# add url via pico_set_program_url
example_auto_set_url(dozo-dd)

#Enable USB I/O
pico_enable_stdio_usb(dozo-dd 1)

#Disable UART I/O
pico_enable_stdio_uart(dozo-dd 0)