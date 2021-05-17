#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <iso646.h>
#include <stdbool.h>
#include "common.h"

int main(int argc, char *argv[]) {
    int *p = malloc(sizeof(int));

    assert(p != NULL);

    printf("(%d) memory address of p: %08x\n",
           getpid(), (unsigned) p);

    *p = 0;

    while (true) {
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }

    return 0;
}
