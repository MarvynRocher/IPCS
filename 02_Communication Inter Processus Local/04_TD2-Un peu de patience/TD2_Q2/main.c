#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    int pid1, pid2;
    int valBoite1=getpid();
    char buffer[255];
    pid1 = fork();
    if (pid1 == 0) {
        
        sprintf(buffer,"mon pid est %d",getpid());
        pid2 = fork();
        if (pid2 == 0) {
            boite("boite2", "pid2=0");
        } else {
            boite("boite3", "pid2<>0");
        }
    } else {
        boite("boite4", "pid1<>0");
    }
    return EXIT_SUCCESS;
}