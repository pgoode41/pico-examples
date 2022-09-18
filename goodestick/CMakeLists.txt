add_executable(goodestick
        goodestick.c
        )

# pull in common dependencies
target_link_libraries(goodestick pico_stdlib hardware_adc)

# create map/bin/hex file etc.
pico_add_extra_outputs(goodestick)

# add url via pico_set_program_url
example_auto_set_url(goodestick)

#Enable USB I/O
pico_enable_stdio_usb(goodestick 1)

#Disable UART I/O
pico_enable_stdio_uart(goodestick 0)