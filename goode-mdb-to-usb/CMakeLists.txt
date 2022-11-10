add_executable(goode-mdb-to-usb
        goode-mdb-to-usb.c
        )

# pull in common dependencies
target_link_libraries(goode-mdb-to-usb pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(goode-mdb-to-usb)

# add url via pico_set_program_url
example_auto_set_url(goode-mdb-to-usb)

#Enable USB I/O
pico_enable_stdio_usb(goode-mdb-to-usb 1)

#Disable UART I/O
pico_enable_stdio_uart(goode-mdb-to-usb 0)