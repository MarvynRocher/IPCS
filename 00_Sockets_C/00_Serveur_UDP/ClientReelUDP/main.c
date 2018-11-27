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
    float reelAEnvoyer = 42.5;
    float reelRecu;
    float retourRecv;
    float retourSend;

    //Création de la socket
    socketClient = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketClient == -1) {
        printf("Problème création socket client : %s \n", strerror(errno));
        exit(errno);
    }
    //init des informations serveurs
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.98");
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(3333);



    int tailleSend = sizeof (infosServeur);

    //envoyer l'entier au serveur
    retourSend = sendto(socketClient, &reelAEnvoyer, sizeof (reelAEnvoyer), 0, (struct sockaddr *) &infosServeur, tailleSend);
    if (retourSend == -1) {
        printf("pb sendto: %s \n", strerror(errno));
        exit(errno);
    }

    //recevoir l'entier du serveur 

    retourRecv = recvfrom(socketClient, &reelRecu, sizeof (reelRecu), 0, (struct sockaddr *) &infosServeur, &tailleSend);
    if (retourRecv == -1) {
        printf("pb recvfrom: %s \n", strerror(errno));
        exit(errno);
    }

    /* Afficher l'entier du serveur */
    printf("Reel recu : %2f", reelRecu);

    return (EXIT_SUCCESS);
}
