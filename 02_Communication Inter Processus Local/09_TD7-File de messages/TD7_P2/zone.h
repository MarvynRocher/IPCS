#ifndef ZONE_H
#define ZONE_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>

struct donnees {
    long type;
    char texte[9];
};
#endif
