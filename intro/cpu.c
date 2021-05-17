#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <iso646.h>
#include <stdbool.h>
#include "common.h"


int main(int argc, char *argv[]) {
    if (argc not_eq 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }

    char *str = argv[1];

    while (true) {
        Spin(1);
        printf("%s\n", str);
    }

    return 0;
}
