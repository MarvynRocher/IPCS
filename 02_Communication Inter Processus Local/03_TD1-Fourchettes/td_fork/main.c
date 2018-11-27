/* question 1 */
/* #include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    fork();
    fork();
    fork();
    printf("* ");


    return EXIT_SUCCESS;
}
 */
/*question 2*/
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int pid1, pid2, pid3;
    pid1 = fork();
    if (pid1 == 0) //p1
    {
        printf("p1\n");
    } else //p4
    {
        pid2 = fork();
        if (pid2 == 0) //p2
        {
            printf("p2\n");
        } else //p4
        {
            pid3 = fork();
            if (pid3 == 0) //p3
            {
                printf("p3\n");
            } else //p4
            {
                printf("p4\n");
            }
        }
    }
    return EXIT_SUCCESS;
}
 */

/* question 5*/
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int pid1, pid2;
    pid1 = fork();
    if (pid1 == 0) {
        boite("boite1", "pid1=0");
        pid2 = fork();
        if (pid2 == 0) {
            boite("boite2", "pid2=0");
        } else {
            boite("boite3", "pid2<>0");
        }
    } else {
        boite("boite4", "pid1<>0");
    }
    return EXIT_SUCCESS;
}
 */

/*question 7*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {

    int pid;
    //p1
    pid = fork();
    if (pid == 0)//p3
    {
        pid = fork();
        if (pid == 0)//p2
        {
            printf("p2");
        } else //p3
        {
            pid = fork();
            if (pid == 0) //p4
            {
                printf("p4");
            } else //p3
            {
                pid = fork();
                if (pid == 0)//p5
                {
                    pid = fork();
                    if (pid == 0)//p6
                    {
                        printf("p6");
                    } else //p5
                    {
                        pid = fork();
                        if (pid == 0)//p7
                        {
                            printf("p7");
                        } else //p5
                        {
                            printf("p5");
                        }
                    }
                } else //p3 
                {
                    printf("p3");
                }
            }
        }
    } else //p1
    {
        printf("p1");
    }

    return (EXIT_SUCCESS);
}
*/