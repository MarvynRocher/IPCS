#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


typedef struct{
	unsigned char jour;
	unsigned char mois;
	unsigned short int annee;
	char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;


int main(int argc, char** argv) {

    int socketClient;
    struct sockaddr_in infosServeur;
    datePerso date;
    int retourConnect;
    int retourWrite;
    int retourRead;
    
    /* Initialisation structure */
    date.annee = 1998;
    date.jour = 28;
    strcpy(date.jourDeLaSemaine, "Lundi");
    date.mois = 12;

    /* Création de la socket client */
    socketClient = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketClient == -1) {
        printf("Problème création socket client : %s \n", strerror(errno));
    }

    /* Init des infos serveur */
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.83");
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(7777);
    int addrlen = sizeof (infosServeur);

    /* Connect */
    retourConnect = connect(socketClient, (struct sockaddr *) &infosServeur, addrlen);

    /* Envoie de l'entier */
    retourWrite = write(socketClient, &date, sizeof (date));

    /* Fin de connection par close*/
    int close(socketClient);

    return (EXIT_SUCCESS);
}

