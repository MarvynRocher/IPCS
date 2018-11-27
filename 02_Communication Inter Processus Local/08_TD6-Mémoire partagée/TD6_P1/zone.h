#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>

#ifndef ZONE_H
#define ZONE_H

#ifdef __cplusplus
extern "C" {
#endif

    struct donnees {
        float temp;
        int press;
        char ordre;

    };


#ifdef __cplusplus
}
#endif

#endif /* ZONE_H */

