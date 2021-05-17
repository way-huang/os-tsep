//
//  fork.c
//  os
//
//  Created by Way on 2021/5/9.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int x;

    x = 100;

    int rc = fork();

    if (rc == 0) {
        // child process
        x = 200;
        printf("child: %d\n", x);
    } else {
        wait(NULL);
        printf("parent: %d\n", x);
    }

    return 0;
}
