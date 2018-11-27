#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int retourSocket;
    struct sockaddr_in infosServeur;
    struct sockaddr_in infosClient;
    int entierRecu;
    int tailleClient;
    int retourBind;
    int retourListen;
    int retourAccept;
    int retourWrite;
    int retourRead;

    printf("serveur TCP port 5555 qui attend un entier");
    retourSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    /* Init des infos serveur */
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(5555);
    infosServeur.sin_addr.s_addr = htonl(INADDR_ANY);

    /* les informations clients */
    tailleClient = sizeof (tailleClient);

    /* bind */
    retourBind = bind(retourSocket, (struct sockaddr*) &infosServeur, sizeof (infosServeur));

    /*Taille de la file d'attente*/
    retourListen = listen(retourSocket, 20);

    /*Acceptation de la connexion*/
    retourAccept = accept(retourSocket, (struct sockaddr*) &infosClient, &tailleClient);

    /*Attente du client*/
    retourRead = read(retourAccept, &entierRecu, sizeof (entierRecu));
    
    /*affichage de la donnée du client*/
    printf("Message du client: %s : %i",inet_ntoa(infosClient.sin_addr),entierRecu);
    entierRecu=-1*entierRecu;
    retourWrite=write(retourAccept, &entierRecu, sizeof(entierRecu));
    
    close(retourSocket);

    return (EXIT_SUCCESS);
}

