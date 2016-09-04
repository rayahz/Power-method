#include "fonctions.h"

#ifdef __i386
extern __inline__ uint64_t rdtsc(void)
{
    uint64_t x;
    __asm__ volatile ("rdtsc" : "=A" (x));
    return x;
}
#elif defined __amd64
extern __inline__ uint64_t rdtsc(void)
{
    uint64_t a, d;
    __asm__ volatile ("rdtsc" : "=a" (a), "=d" (d));
    return (d<<32) | a;
}
#endif

int main(int argc, char *argv[])
{
    /* *** DECLARATION DES VARIABLES *** */
    int ligne, colonne;
    double *A, *b;
    uint64_t timer_start, timer_end;

    /* *** INITIALISATION DES VARIABLES *** */
    saisie_proprietes(&ligne, &colonne);
    A = calloc(ligne * colonne, sizeof(double));
    b = calloc(ligne, sizeof(double));
    saisie_matrice(ligne, colonne, A);
    saisie_vecteur(ligne, b);

    /* *** CORPS DU PROGRAMME PRINCIPAL *** */
    timer_start = rdtsc();
    power_method(ligne, A, b);
    timer_end = rdtsc();

    fprintf(stdout, "\nTemps de l'execution : %e s\n",
            (timer_end - timer_start) / 2.9E9);

    /* *** LIBERATION DES RESSOURCES *** */
    free(A);
    free(b);

    return 0;
}

