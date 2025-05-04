#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int _write(int fd, const char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        extern void uart_putc(char c);
        uart_putc(ptr[i]);
    }
    return len;
}

void *_sbrk(ptrdiff_t incr) {
    extern char _end;
    static char *heap_end = &_end;
    char *prev_heap = heap_end;
    heap_end += incr;
    return (void *)prev_heap;
}

int _read(int fd, char *ptr, int len) {
    errno = ENOSYS;
    return -1;
}
int _close(int fd) {
    errno = ENOSYS;
    return -1;
}
int _fstat(int fd, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}
int _isatty(int fd) { return 1; }
int _lseek(int fd, int ptr, int dir) { return 0; }
void _exit(int status) {
    while (1) {
    }
}
int _kill(int pid, int sig) {
    errno = ENOSYS;
    return -1;
}
int _getpid(void) { return 1; }
