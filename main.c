#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "calcul.h"

/*int main() {
    int max;
    do {
        printf("\nVeuillez saisir la longueur maximale du tableau:\nVeuillez ne pas dépasser 10000 : ");
        if (scanf("%d", &max) != 1 || max > 10000) {
            fprintf(stderr, "Entrée non valide. Veuillez saisir une longueur valide (jusqu'à 10000).\n");
            exit(1);
        }
    } while (max > 10000);

    printf("Le programme prendra du temps. Veuillez attendre, Merci!");

    int* T = NULL;
    int i;
    bulleComplexity[0] = insertionComplexity[0] = selectionComplexity[0] = fusionComplexity[0] = rapideComplexity[0] = shakerComplexity[0] = gnomeComplexity[0] = peigneComplexity[0] = shellComplexity[0] = 0;

    for (i = 1; i <= max; i++) {
        // Inform the user about the current scenario

        // Generate and measure complexity for a sorted array in ascending order
        T = generateSortedArray(i, 1);
        if (T == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire");
            exit(1);
        }
        measureSortingComplexity(T, i);

        // Generate and measure complexity for a sorted array in descending order
        T = generateSortedArray(i, -1);
        if (T == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire");
            exit(1);
        }
        measureSortingComplexity(T, i);

        // Generate and measure complexity for a random array
        T = generateRandomArray(T, i);
        if (T == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire");
            exit(1);
        }
        measureSortingComplexity(T, i);

        // Free allocated memory
        free(T);
    }

    // Save the measured data to CSV files and generate graphs
    saveTimeCSV(max);
    tracerGraph();
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateAndTestData(int n, int scenarios) {
    int* T = NULL;

 if (scenarios & 4) {
        scenarios = 6; // Test all three scenarios individually
    }

    for (int i = 1; i <= n; i++) {
        if (scenarios & 1) {
            T = generateSortedArray(i, 1);
            measureSortingComplexity(T, i);
            free(T);
        }

        if (scenarios & 2) {
            T = generateSortedArray(i, -1);
            measureSortingComplexity(T, i);
            free(T);
        }

        if (scenarios & 3) {
            T = generateRandomArray(T, i);
            measureSortingComplexity(T, i);
            free(T);
        }
       

    }
}

int main() {
    int max;
    do {
        printf("\nVeuillez saisir la longueur maximale du tableau:\nVeuillez ne pas dépasser 10000 : ");
        if (scanf("%d", &max) != 1 || max > 10000) {
            fprintf(stderr, "Entrée non valide. Veuillez saisir une longueur valide (jusqu'à 10000).\n");
            exit(1);
        }
    } while (max > 10000);

    printf("Le programme prendra du temps. Veuillez attendre, Merci!\n");

    int choice;
    do {
        printf("\nVeuillez choisir les scénarios (entrez le nombre correspondant) :\n");
        printf("1. Tri avec données triées \n");
        printf("2. Tri avec données triées en ordre inverse\n");
        printf("3. Tri avec données aléatoires\n");
        printf("4. Tous les scénarios\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 15);

    generateAndTestData(max, choice);

    // Save the measured data to CSV files and generate graphs
    saveTimeCSV(max);
    tracerGraph();

    return 0;
}
