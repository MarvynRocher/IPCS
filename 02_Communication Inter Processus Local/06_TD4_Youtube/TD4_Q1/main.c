#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {
    FILE *fd;
    char buffer[255];
    int nbRead;

    fd = popen("/bin/uname", "r");
    if (fd == NULL) {
        printf("Pb avec popen : %s", strerror(errno));
        exit(0);
    }
    nbRead = fread(buffer, sizeof (buffer), 1, fd);
    printf("%s", buffer);
    pclose(fd);

    return (EXIT_SUCCESS);
}

