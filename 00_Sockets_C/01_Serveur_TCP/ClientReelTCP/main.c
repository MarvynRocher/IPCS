#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char** argv) {

    int socketClient;
    struct sockaddr_in infosServeur;
    float ReelAEnvoyer = 3.14;
    float ReelRecu;
    int retourConnect;
    int retourWrite;
    int retourRead;

    /* Création de la socket client */
    socketClient = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketClient == -1) {
        printf("Problème création socket client : %s \n", strerror(errno));
    }

    /* Init des infos serveur */
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.83");
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(6666);
    int addrlen = sizeof (infosServeur);

    /* Connect */
    retourConnect = connect(socketClient, (struct sockaddr *) &infosServeur, addrlen);

    /* Envoie de l'entier */
    retourWrite = write(socketClient, &ReelAEnvoyer, sizeof (ReelAEnvoyer));

    /* Reception de l'entier */
    retourRead = read(socketClient, &ReelRecu, sizeof (ReelRecu));

    /* Fin de connection par close*/
    int close(int socketClient);

    /* Afficher du reel du serveur */
    printf("Réel recu : %f", ReelRecu);

    return (EXIT_SUCCESS);
}


