#include "zone.h"

float randomF() {
    return ((float) 100.0 * (rand() / (RAND_MAX + 0.1)));
}

int randomI() {
    return ((int) 100.0 * (rand() / (RAND_MAX + 0.1)));
}

int main(int argc, char** argv) {

    struct donnees *zonePartage;
    int id;
    key_t key;

    /* création de la clé */
    if ((key = ftok("/tmp/bidon", 1234)) == -1) {
        perror("ftok");
        exit(2);
    }

    /*Création de la zone de mémoire à partager */
    id = shmget(key, sizeof (struct donnees), IPC_CREAT | 0600);
    if (id == -1) {
        if (errno != EEXIST) {
            printf("pb shmget : %s \n", strerror(errno));
        }
    }

    /* Attribution de l'adresse visuelle au segment */
    zonePartage = (struct donnees *) shmat(id, NULL, SHM_W);
    if (zonePartage == NULL) {
        perror("shmat");
        exit(1);
    }

    /* Écriture continue des valeurs aléatoires dans la zonePartage */
    while (1) {
        zonePartage->temp = randomF();
        zonePartage->press = randomI();
        printf("temp : %.2f press : %d \n", zonePartage->temp, zonePartage->press);
        sleep(1);
    }

    return (EXIT_SUCCESS);
}



