#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void traitement(int sig) {
    (void)signal(SIGUSR1,traitement);
    printf("reception de signal je suis %d \n",getpid());
}

int main(int argc, char** argv) {
    int pid;
    int pidP3;
    int pidP3Reception;
    int tube[2];
    (void) signal(SIGUSR1, traitement);
    //P1
    //création tube
    if (pipe(tube) == 0) {
        pid = fork();
        if (pid == 0)//P2
        {
            pid = fork();
            if (pid == 0) //P3
            {
                printf("pid p3 : %d\n", getpid());
                pidP3 = getpid();
                //écriture pidP3 dans le tube
                write(tube[1], &pidP3, sizeof (pidP3));
                pause();
            } else //P2
            {
                printf("pid p2 : %d\n", getpid());
                pause();
            }
        } else //P1 
        {
            printf("pid p1 : %d\n", getpid());
            kill(pid, SIGUSR1);
            //lecture pidP3 dans le tube
            read(tube[0], &pidP3Reception, sizeof (int));
            kill(pidP3Reception, SIGUSR1);
        }
    }
}