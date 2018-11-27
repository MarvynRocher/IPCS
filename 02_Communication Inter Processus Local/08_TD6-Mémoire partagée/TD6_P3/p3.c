#include "zone.h"

int main(int argc, char** argv) {

    struct donnees *zonePartage;
    int id;
    key_t key;

    /* création de la clé */
    if ((key = ftok("/tmp/bidon", 1234)) == -1) {
        perror("ftok");
        exit(2);
    }

    /* Création de la zone mémoire à partager */
    id = shmget(key, sizeof (struct donnees), IPC_CREAT | 0666); // autorisation de lire & écrire
    if (id == -1) {
        perror("pb shmget");
        exit(1);
    }

    /* Attribution de l'adresse visuelle au segment */
    zonePartage = (struct donnees *) shmat(id, NULL, SHM_W);
    if (zonePartage == NULL) {
        perror("shmat");

    }

    /* Écriture continue des valeurs aléatoires dans la zonePartage */

    while (1) {
        printf("ordre : %c temp : %.2f press : %d \n", zonePartage->ordre, zonePartage->temp, zonePartage->press);
        sleep(1);
    }
    return (EXIT_SUCCESS);
}

