#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "methodetri.h"
#include <string.h>

#define MAX_POINTS 10000

int *randise(int T[], int );

 double bulleComplexity[MAX_POINTS];
 double insertionComplexity[MAX_POINTS];
 double selectionComplexity[MAX_POINTS];
 double fusionComplexity[MAX_POINTS];
 double rapideComplexity[MAX_POINTS];
 double shakerComplexity[MAX_POINTS];
 double gnomeComplexity[MAX_POINTS];
 double peigneComplexity[MAX_POINTS];
 double shellComplexity[MAX_POINTS];


 //Création de la fonction pour générer des nombres aléatoires , cela va me servir pour remplir le tableau 

int* generateRandomArray(int T[], int T1 ){
    T = (int*)malloc( sizeof(int) * T1 );
     if (T == NULL) {
        // Handle memory allocation error
        exit(1);
    }
    srand(time(NULL));
    for( int i = 0; i< T1 ;i++ ){
        T[i] = rand() % 200;
    }
   return T; 
}

int* generateSortedArray(int length, int order) {
    int* array = (int*)malloc(length * sizeof(int));
    if (array == NULL) {
        // Handle memory allocation error
        exit(1);
    }

    if (order == 1) {  // Ascending order
        for (int i = 0; i < length; i++) {
            array[i] = i;
        }
    } else if (order == -1) {  // Descending order
        for (int i = 0; i < length; i++) {
            array[i] = length - i - 1;
        }
    }

    return array;
}


//Calcul et stockage du temps de tri , au lieu de répéter la fonction , cette focntion reçoit les paramétres similaires pour un traitement pareils.

void measureSortingTime(void (sortingFunction)(int *, int), int* T, int T1, double* complexityArray) {
    clock_t start, end;
    
//Le tri du tablea 

    start = clock();
    sortingFunction(T, T1);
    end = clock();

//le calcul et le stockage de la complexité 

    complexityArray[T1] = ((double)(end - start));


}


//Cette méthode permet d'implementer la méthode ci-dessus

void measureSortingComplexity(int *T, int T1) {   

    // Measure time for each sorting algorithm
    measureSortingTime(triBulle, T, T1, bulleComplexity);
    measureSortingTime(triInsertion, T, T1, insertionComplexity);
    measureSortingTime(triSelection, T, T1, selectionComplexity);
    measureSortingTime(triFusion, T, T1, fusionComplexity);
    measureSortingTime(triRapide, T, T1, rapideComplexity);
    measureSortingTime(triRapide, T, T1, shakerComplexity);
    measureSortingTime(triRapide, T, T1, gnomeComplexity);
    measureSortingTime(triRapide, T, T1, peigneComplexity);
    measureSortingTime(triRapide, T, T1, shellComplexity);

      
}

//la focntion de la moyenne pondérée  : 

void dataSmoothing(const double *data, double *smoothed_data, int num_points, int window_size) {
    for (int i = 0; i < num_points; i++) {
        double sum = 0.0;
        int count = 0;

        for (int j = i - window_size / 2; j <= i + window_size / 2; j++) {
            if (j >= 0 && j < num_points) {
                sum += data[j];
                count++;
            }
        }
        smoothed_data[i] = count > 0 ? sum / count : data[i];
    }
}


//Fonction pour créer des fichiers pour l'interpretation graphique
void saveTimeCSV(int n)
{
    FILE *bulle = fopen("bulleCSV.csv", "w");
    FILE *insertion = fopen("insertionCSV.csv", "w");
    FILE *selection = fopen("selectionCSV.csv", "w");
    FILE *fusion = fopen("fusionCSV.csv", "w");
    FILE *rapide = fopen("rapideCSV.csv", "w");
    FILE *shaker = fopen("shakerCSV.csv", "w");
    FILE *gnome = fopen("gnomeCSV.csv", "w");
    FILE *peigne = fopen("peigneCSV.csv", "w");
    FILE *shell = fopen("shellCSV.csv", "w");


    double bulleLisse[n];
    double insertionLisse[n];
    double selectionLisse[n];
    double fusionLisse[n];
    double rapideLisse[n];
    double shakerLisse[n];
    double gnomeLisse[n];
    double peigneLisse[n];
    double shellLisse[n];

    dataSmoothing(bulleComplexity, bulleLisse, n, 50);
    dataSmoothing(insertionComplexity,insertionLisse,n,50);
    dataSmoothing(selectionComplexity,selectionLisse,n,50);
    dataSmoothing(fusionComplexity, fusionLisse, n, 50);
    dataSmoothing(rapideComplexity, rapideLisse, n, 50);
    dataSmoothing(shakerComplexity, shakerLisse, n, 50);
    dataSmoothing(gnomeComplexity, gnomeLisse, n, 50);
    dataSmoothing(peigneComplexity, peigneLisse, n, 50);
    dataSmoothing(shellComplexity, shellLisse, n, 50);



    for (int i = 0; i < n; i++)
    {
        fprintf(bulle, "%d,%.4f\n", i, bulleLisse[i]);
        fprintf(insertion, "%d,%.4f\n", i, insertionLisse[i]);
        fprintf(selection, "%d,%.4f\n", i, selectionLisse[i]);
        fprintf(fusion, "%d,%.4f\n", i, fusionLisse[i]);
        fprintf(rapide, "%d,%.4f\n", i, rapideLisse[i]);
        fprintf(shaker, "%d,%.4f\n", i, shakerLisse[i]);
        fprintf(gnome, "%d,%.4f\n", i, gnomeLisse[i]);
        fprintf(peigne, "%d,%.4f\n", i, peigneLisse[i]);
        fprintf(shell, "%d,%.4f\n", i, shellLisse[i]);

    }

    fclose(bulle);
    fclose(insertion);
    fclose(selection);
    fclose(fusion);
    fclose(rapide);
    fclose(shaker);
    fclose(gnome);
    fclose(peigne);
    fclose(shell);

}


//fonction qui permet de tracer la courbe 

void tracerGraph()
{
    char cmd[100];
    strcpy(cmd, "gnuplot plot.gnuplot");
    system(cmd);
}



