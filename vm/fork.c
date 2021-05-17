//
//  fork.c
//  os
//
//  Created by Way on 2021/5/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    if (rc == 0) {
        close(STDOUT_FILENO);
        open("./fork.out", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

        char *args[3];

        args[0] = strdup("wc");
        args[1] = strdup("fork.c");
        args[2] = NULL;

        execvp(args[0], args);
    } else {
        int wc = wait(NULL);
    }

    return 0;
}
