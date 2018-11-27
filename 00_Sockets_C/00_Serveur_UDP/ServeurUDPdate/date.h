/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   date.h
 * Author: mvillermin
 *
 * Created on 14 septembre 2018, 11:26
 */

#ifndef DATE_H
#define DATE_H

#ifdef __cplusplus
extern "C" {
#endif
    
typedef struct{
	unsigned char jour;
	unsigned char mois;
	unsigned short int annee;
	char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;



#ifdef __cplusplus
}
#endif

#endif /* DATE_H */

