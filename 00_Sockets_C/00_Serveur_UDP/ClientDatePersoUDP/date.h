#ifndef DATE_H
#define DATE_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned char jour;
        unsigned char mois;
        unsigned short int annee;
        char jourDeLaSemaine[10]; // le jour en toute lettre
    } datePerso;


#ifdef __cplusplus
}
#endif

#endif /* DATE_H */
