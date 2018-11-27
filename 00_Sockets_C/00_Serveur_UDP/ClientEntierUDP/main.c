#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv) {

    int socketClient;
    struct sockaddr_in infosServeur;
    int entierAEnvoyer = 42;
    int entierRecu;
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
    infosServeur.sin_port = htons(2222);


    int tailleSend = sizeof (infosServeur);
    while (1 == 1) {
        //envoyer l'entier au serveur
        retourSend = sendto(socketClient, &entierAEnvoyer, sizeof (entierAEnvoyer), 0, (struct sockaddr *) &infosServeur, tailleSend);
        if (retourSend == -1) {
            printf("pb sendto: %s \n", strerror(errno));
            exit(errno);
        }

        //recevoir l'entier du serveur 

        retourRecv = recvfrom(socketClient, &entierRecu, sizeof (entierRecu), 0, (struct sockaddr *) &infosServeur, &tailleSend);
        if (retourRecv == -1) {
            printf("pb recvfrom: %s \n", strerror(errno));
            exit(errno);
        }

        /* Afficher l'entier du serveur */
        printf("Entier recu : %d", entierRecu);

    }
    return (EXIT_SUCCESS);
}



