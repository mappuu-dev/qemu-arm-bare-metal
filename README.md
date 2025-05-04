# Embedded Baremetal Project

This project is a baremetal embedded application designed to run on ARM architectures. It includes a simple program that outputs messages via UART and demonstrates basic embedded system concepts. While the current example targets the ARM926EJ-S processor, the project is designed to be adaptable to other ARM processors with minimal modifications.

## Project Structure

```
CMakeLists.txt
hello_embedded.code-workspace
toolchain_arm.cmake
linker/
    arm_versatilepb.ld
src/
    main.c
    startup.s
    syscalls.c
    uart.c
```

## Features

- **Baremetal Programming**: No operating system, directly interacts with hardware.
- **UART Communication**: Implements basic UART functions for character and string output.
- **Custom Linker Script**: Defines memory layout and sections for the ARM platform.
- **Minimal Syscalls**: Provides basic `_write`, `_sbrk`, and other syscall stubs for compatibility with standard C library functions like `printf`.

## Prerequisites

- **Toolchain**: ARM GCC toolchain (`arm-none-eabi-gcc`, `arm-none-eabi-ld`, etc.).
- **CMake**: Version 3.20 or higher.
- **Ninja**: Build system generator.
- **QEMU**: For running the application in an ARM emulator (optional).

## Building the Project

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd qemu-arm-bare-metal
   ```

2. Create a build directory and configure the project:
   ```bash
   cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="toolchain_arm.cmake" -DTARGET_MACHINE="<target machine>"
   ```
   
   `<target machine>` is same as qemu's -M options.

3. Build the project:
   ```bash
   cmake --build build --clean-first
   ```

4. The output files (`baremetal.elf` and `baremetal.bin`) will be generated in the `build/` directory.

## Running the Application

### Using QEMU

You can run the application in QEMU with the following command:
```bash
qemu-system-arm -M versatilepb -nographic -kernel build/baremetal.bin
```

### Expected Output

When running the application, you should see the following output in the terminal:
```
Hello Embedded from QEMU!
Tick!(1)
Tick!(2)
...
Tick!(10)
End of program.
```

## Customization

- Modify `src/main.c` to change the application logic.
- Adjust the memory layout in `linker/*.ld` as needed.
- Update `CMakeLists.txt` to add or remove source files or compiler flags.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
