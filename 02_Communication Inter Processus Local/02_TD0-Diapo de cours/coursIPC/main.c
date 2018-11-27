#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int retour; 
    retour=system("uname -rom");
    if(retour==1){
       printf("pb avec l'appel de la fonction system");
       exit(0);
    }

    return (EXIT_SUCCESS);
}

