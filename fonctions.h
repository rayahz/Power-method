#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <cblas.h>
#include <lapacke.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define DBL_EPSILON 0.00001

void affichage(int, int, double*);
void saisie_matrice(int, int, double *);
void saisie_proprietes(int *, int *);
void saisie_vecteur(int, double *);
void matVec(int, double *, double *, double *);
void power_method(int, double *, double *);

#endif
