#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZ 255

int main() {
    int pid;
    int tube[2];
    int tube2[2];
    char *msg = "coucou";
    char buffer[255];
    if (pipe(tube) == 0) {//P1
        if (pipe(tube2)) {
            pid = fork();
            if (pid == 0) //P2
            {
                memset(buffer, 0, 255);
                read(tube[0], buffer, 255);
                printf("msg de P1 : %s \n", buffer);
                write(tube2[1], msg, strlen(msg));
            } else //P1
            {
                sleep(2);
                write(tube[1], msg, strlen(msg));
                read(tube2[0], buffer, 255);
            }
        }
        exit(EXIT_FAILURE);
    }
}

