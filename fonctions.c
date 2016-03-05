#include "fonctions.h"

/*
*  NAME        : affichage
*  DESCRIPTION : permet d'afficher une matrice ou vecteur
*  IN          : nombre de ligne, nombre de colonne, matrice ou vecteur à afficher
*  OUT         : /
*  DEBUG       : /
*/
void affichage(int M, int N, double *A)
{
	int i, j;

	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
			fprintf(stdout, " %lf\t", A[i * N + j]);
		fprintf(stdout, "\n");
	}
}

/*
*  NAME        : matVec
*  DESCRIPTION : permet d'effectuer un produit matrice vecteur
*  IN          : nombre de ligne, matrice, vecteur operande, vecteur resultat
*  OUT         : /
*  DEBUG       : /
*/
void matVec(int n, double *a, double *x, double *b)
{
	int i, j;

	for(i = 0; i < n; i++)
	{
		b[i] = 0.;
		for(j = 0; j < n; j++)
			b[i] += a[i * n + j] * x[j];
	}

}

/*
*  NAME        : power_method
*  DESCRIPTION : permet d'effectuer la methode de la puissance
*  IN          : nombre de ligne, matrice, vecteur 
*  OUT         : /
*  DEBUG       : /
*/
void power_method(int n, double *a, double *x)
{
	double *tmp = malloc(n * sizeof(double));
	double d = 0, dOld;

	do
	{
		// tmp = ax
		matVec(n, a, x, tmp);

		for(int i = 0; i < n; i++)
			x[i] = tmp[i];

		dOld = d;
		d = 0;

		for(int i = 0; i < n; i++)
		{
			if(fabs(x[i]) > fabs(d))
				d = x[i];
		}

		for(int i = 0; i < n; i++)
			x[i] /= d;

	}while(fabs(d - dOld) > DBL_EPSILON);

	fprintf(stdout, "\nValeur propre = %lf\n", d);

	fprintf(stdout, "\nVecteur propre\n");
	affichage(n, 1, x);

	free(tmp);
}

/*
*  NAME        : saisie_matrice
*  DESCRIPTION : permet de saisir manuellement une matrice
*  IN          : nombre de ligne, nombre de colonne, matrice
*  OUT         : /
*  DEBUG       : /
*/
void saisie_matrice(int ligne, int colonne, double *a)
{
	fprintf(stdout, "\nSaisie de la matrice %d, %d\n", ligne, colonne);

	for(int i = 0; i < ligne; i++)
	{
		for(int j = 0; j < colonne; j++)
		{
			fprintf(stdout, "(%d, %d) ?\t", i, j);
			double valeur;
			int erreur = scanf("%lf", &valeur);

			if(erreur == 0)
				a[i * colonne + j] = 0.;
			else 
				a[i * colonne + j] = valeur;
		}
	}

	fprintf(stdout, "\nVoici la matrice que vous avez saisie\n");
	affichage(ligne, colonne, a);
}

/*
*  NAME        : saisie_vecteur
*  DESCRIPTION : permet de saisir manuellement un vecteur
*  IN          : nombre de ligne, vecteur
*  OUT         : /
*  DEBUG       : /
*/
void saisie_vecteur(int ligne, double *a)
{
	fprintf(stdout, "\nSaisie du vecteur\n");

	for(int i = 0; i < ligne; i++)
	{
		fprintf(stdout, "(%d) ?\t", i);
		double valeur;
		int erreur = scanf("%lf", &valeur);

		if(erreur == 0)
			a[i] = 0.;
		else 
			a[i] = valeur;
	}

	fprintf(stdout, "\nVoici le vecteur que vous avez saisie\n");
	affichage(ligne, 1, a);
}

/*
*  NAME        : saisie_proprietes
*  DESCRIPTION : permet de saisir le nombre de lignes, colonnes et valeurs propres à calculer
*  IN          : nombre de ligne, nombre de colonne, nombres de valeurs propres
*  OUT         : /
*  DEBUG       : /
*/
void saisie_proprietes(int *ligne, int *colonne)
{
	fprintf(stdout, "Nombre de ligne ?\t");
	if(scanf("%d", ligne) == 0)
		fprintf(stderr, "Veuillez entrer au moins un nombre\n");

	fprintf(stdout, "Nombre de colonne ?\t");
	if(scanf("%d", colonne) == 0)
		fprintf(stderr, "Veuillez entrer au moins un nombre\n");

	// uniquement les matrices carrees
	if(*ligne != *colonne)
	{
		fprintf(stderr, "La matrice doit être carrée\n");
		abort();
		exit(EXIT_FAILURE);
	}
}
