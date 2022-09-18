# Install script for directory: /home/preston/Documents/pico-sdk/pico-examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/arm-none-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/pico-sdk/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/blink/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/hello_world/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/adc/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/clocks/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/cmake/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/divider/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/dma/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/flash/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/gpio/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/i2c/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/interp/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/multicore/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/picoboard/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/pico_w/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/pio/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/pwm/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/reset/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/rtc/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/spi/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/system/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/timer/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/uart/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/usb/cmake_install.cmake")
  include("/home/preston/Documents/pico-sdk/pico-examples/blink/watchdog/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/preston/Documents/pico-sdk/pico-examples/blink/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
