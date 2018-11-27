#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZ 255

/* 1ère version du programme*/

int main() {
    int nbOctets;
    int tube[2];
    const char chaine[] = "Salut papa !";
    char buffer[BUFSIZ];
    pid_t pid;
    memset(buffer, '\0', BUFSIZ);

    if (pipe(tube) == 0) { //création du tube 
        pid = fork(); // duplication du processus
        if (pid == -1) { // oups un probleme
            fprintf(stderr, "Pb de fork");
            exit(EXIT_FAILURE);
        } else // fork ok
        {
            if (pid > 0) { // je suis dans le process pere
                nbOctets = read(tube[0], buffer, BUFSIZ);
                printf("octets lus: %d: %s\n", nbOctets, buffer);
                exit(EXIT_SUCCESS);
            } else //je suis dans le process fils
            {
                nbOctets = write(tube[1], chaine, strlen(chaine));
                printf("%d octets ecrits\n", nbOctets);
            }
        }
        exit(EXIT_FAILURE);
    }
}

/* 2e version mieux rédigée du programme */
/*int main() {
    int pid;
    int tube[2];
    char *msg = "coucou";
    char buffer[255];
    if (pipe(tube) == 0) {//P1
        pid = fork();
        if (pid == 0) //P2
        {
            memset(buffer, 0, 255);
            read(tube[0], buffer, 255);
            printf("msg de P1 : %s \n", buffer);
        } else //P1
        {
            sleep(2);
            write(tube[1], msg, strlen(msg));
        }
    }
    exit(EXIT_FAILURE);
}
*/