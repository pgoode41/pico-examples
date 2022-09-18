add_executable(dozo-arcade-ca
        dozo-arcade-ca.c
        )

# pull in common dependencies
target_link_libraries(dozo-arcade-ca pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(dozo-arcade-ca)

# add url via pico_set_program_url
example_auto_set_url(dozo-arcade-ca)

#Enable USB I/O
pico_enable_stdio_usb(dozo-arcade-ca 1)

#Disable UART I/O
pico_enable_stdio_uart(dozo-arcade-ca 0)