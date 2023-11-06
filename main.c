#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "calcul.h"

void generateAndTestData(int *tableau, int n, int scenarios)
{
    switch (scenarios)
    {
    case 1:
        for (int i = 1; i <= n; i++)
        {
            tableau = generateSortedArray(tableau, i, 1);
            measureSortingComplexity(tableau, i);
        }
        saveTimeCSV(n);
        tracerGraph("courbeAsc.gnuplot");
        break;
    case 2:
        for (int i = 1; i <= n; i++)
        {
            tableau = generateSortedArray(tableau, i, 2);
            measureSortingComplexity(tableau, i);
        }
        saveTimeCSV(n);
        tracerGraph("courbeDesc.gnuplot");
        break;
    case 3:
        for (int i = 1; i <= n; i++)
        {
            tableau = generateRandomArray(tableau, i);
            measureSortingComplexity(tableau, i);
        }
        saveTimeCSV(n);
        tracerGraph("courbeAleatoire.gnuplot");
        break;
    case 4:
        for (int i = 1; i <= n; i++)
        {
            tableau = generateRandomArray(tableau, i);
            measureSortingComplexity(tableau, i);
        }
        saveTimeCSV(n);
        tracerGraph("courbeAleatoire.gnuplot");

        for (int i = 1; i <= n; i++)
        {
            tableau = generateSortedArray(tableau, i, 1);
            measureSortingComplexity(tableau, i);
        }
        saveTimeCSV(n);
        tracerGraph("courbeAsc.gnuplot");

        for (int i = 1; i <= n; i++)
        {
            tableau = generateSortedArray(tableau, i, 2);
            measureSortingComplexity(tableau, i);
        }
        saveTimeCSV(n);
        tracerGraph("courbeDesc.gnuplot");
        break;
    case 0:
        break;
    default:
        printf("INFO: Entrez un choix Valide !!\n");
        break;
    }
}

int main()
{
    int max;
    do
    {
        printf("\nVeuillez saisir la longueur maximale du tableau:\nVeuillez ne pas dépasser 10000 : ");
        if (scanf("%d", &max) != 1 || max > 10000)
        {
            fprintf(stderr, "Entrée non valide. Veuillez saisir une longueur valide (jusqu'à 10000).\n");
            exit(1);
        }
    } while (max > 10000);

    printf("Le programme prendra du temps. Veuillez attendre, Merci!\n");

    int choice;
    do
    {
        printf("\nVeuillez choisir les scénarios (entrez le nombre correspondant) :\n");
        printf("1. Tri avec données triées \n");
        printf("2. Tri avec données triées en ordre inverse\n");
        printf("3. Tri avec données aléatoires\n");
        printf("4. Tous les scénarios\n");
        printf("0. Sortir de Menu\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
    } while (choice < 0 && choice > 4);

    // Tableau qu'on va triee
    int *T = NULL;

    generateAndTestData(T, max, choice);

    return 0;
}
