#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include "date.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int socketClient;
    struct sockaddr_in infosServeur;
    datePerso entierAEnvoyer;
    entierAEnvoyer.jour = 28;
    entierAEnvoyer.mois = 03;
    entierAEnvoyer.annee = 2018;
    strcpy(entierAEnvoyer.jourDeLaSemaine, "vendredi");
    float entierRecu;
    int retourRecv;
    int retourSend;

    //Création de la socket
    socketClient = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketClient == -1) {
        printf("Problème création socket client : %s \n", strerror(errno));
        exit(errno);
    }
    //init des informations serveurs
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.83");
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(4444);

    int tailleSend = sizeof (infosServeur);

    //envoyer l'entier au serveur
    retourSend = sendto(socketClient, &entierAEnvoyer, sizeof (entierAEnvoyer), 0, (struct sockaddr *) &infosServeur, tailleSend);
    if (retourSend == -1) {
        printf("Probleme sendto: %s \n", strerror(errno));
        exit(errno);
    }

    return (EXIT_SUCCESS);
}

