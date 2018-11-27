#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>

                                                        /*UDP --> reçoit et envoie un réel */
int main(int argc, char** argv) {

    int retourSocket;
    struct sockaddr_in infosServeur;
    struct sockaddr_in infosClient;
    int retourBind;
    int retourRcv;
    int retourSend;
    int tailleClient;
    float reelRecu;

    printf("serveur UDP sur port 2222 attend un ENTIER\n");
    retourSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    /* Infos du serveur */
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(3333); //numero de port du serveur 
    infosServeur.sin_addr.s_addr = INADDR_ANY; // adresse IP du serveur 

    /* Bind */
    retourBind = bind(retourSocket, (struct sockaddr*) &infosServeur, sizeof (infosServeur));

    tailleClient = sizeof (infosClient);
    while(1==1){
    /* Attente des données client */
    retourRcv = recvfrom(retourSocket, &reelRecu, sizeof (reelRecu), 0, (struct sockaddr *) &infosClient, &tailleClient);

    /* Affichage des données client */
    printf("Message du client %s : %f\n", inet_ntoa(infosClient.sin_addr), reelRecu);

    /* Rajoute un "-" devant l'entier reçu */
    reelRecu = -reelRecu;

    /* Renvoie de l'entier reçu */
    retourSend = sendto(retourSocket, &reelRecu, sizeof (reelRecu), 0, (struct sockaddr *) &infosClient, sizeof (infosClient));

    }
    return EXIT_SUCCESS;
    
}


