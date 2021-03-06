#include <string.h>
#include "zone.h"

float randomC() {
    return ((char) ('A' + ((char) 24.0 * (rand() / (RAND_MAX + 0.1)))));
}

int main(int argc, char** argv) {
    struct donnees maFile;
    int idFile;

    /*Obtention de la clé*/
    key_t key;
    if ((key = ftok("/tmp/bidon", 5678)) == -1) {
        perror("ftok");
        exit(2);
    }
    /* obtention de la file pour la clé key*/
    idFile = msgget(key, 0666 | IPC_CREAT);
    if (idFile == -1) {
        printf("Pb creation file : %s \n", strerror(errno));
        exit(0);
    }
    while (1) {
        maFile.texte[0] = randomC();
        maFile.type = 3;
        msgsnd(idFile,(void*) &maFile,sizeof(char), IPC_NOWAIT);
        sleep(1);
    }

    return (EXIT_SUCCESS);
}

