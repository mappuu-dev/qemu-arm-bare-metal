cmake_minimum_required(VERSION 3.20)
project(baremetal C CXX ASM)

add_executable(${PROJECT_NAME}.elf
    src/startup.s
    src/main.c
    src/syscalls.c
    src/uart.c
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=arm926ej-s -ffreestanding -g")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=arm926ej-s -g")

target_link_options(${PROJECT_NAME}.elf PRIVATE
    -T${CMAKE_SOURCE_DIR}/linker/arm_versatilepb.ld
    -nostartfiles
    -lc
)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O binary baremetal.elf baremetal.bin
)
