#include <stdio.h>

void main(void) {
    int j = 0;

    printf("Hello Embedded from QEMU!\n");

    while (1) {
        for (volatile unsigned int i = 0; i < 100000000; i++)
            ;

        j++;
        char buffer[32];
        sprintf(buffer, "Tick!(%d)\n", j);
        printf(buffer);

        if (j > 9) {
            break;
        }
    }

    printf("End of program.\n");
}
