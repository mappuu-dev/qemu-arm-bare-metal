#ifdef CONFIG_VEXPRESS_A9
#define UART_BASE 0x10009000
#endif

#ifdef CONFIG_VEXPRESS_A15
#define UART_BASE 0x1c090000
#endif

#ifdef CONFIG_VERSATILEPB
#define UART_BASE 0x101f1000
#endif

#define UART_DR (*(volatile unsigned int *)(UART_BASE + 0x00))
#define UART_FR (*(volatile unsigned int *)(UART_BASE + 0x18))
#define UART_FR_TXFF 0x20

void uart_putc(char c) {
    while (UART_FR & UART_FR_TXFF) {
    }
    UART_DR = c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

int putchar(int c) {
    uart_putc((char)c);
    return c;
}
