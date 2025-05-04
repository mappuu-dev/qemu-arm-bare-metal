cmake_minimum_required(VERSION 3.20)
project(baremetal C CXX ASM)

add_executable(${PROJECT_NAME}.elf
    src/startup.s
    src/main.c
    src/syscalls.c
    src/uart.c
)

if(TARGET_MACHINE STREQUAL "vexpress-a9")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-a9 -DCONFIG_VEXPRESS_A9")
    set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=cortex-a9")
    target_link_options(${PROJECT_NAME}.elf PRIVATE -T${CMAKE_SOURCE_DIR}/linker/arm_vexpress_a9.ld)
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=arm926ej-s -DCONFIG_VERSATILEPB")
    set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=arm926ej-s")
    target_link_options(${PROJECT_NAME}.elf PRIVATE -T${CMAKE_SOURCE_DIR}/linker/arm_versatilepb.ld)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffreestanding -g")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -g")

target_link_options(${PROJECT_NAME}.elf PRIVATE
    -nostartfiles
    -lc
)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
)
