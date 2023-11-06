
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// les fonctions :

void triBulle(int *, int);
void triSelection(int *, int);
void triInsertion(int *, int);
void triRapide(int *, int);
void triFusion(int *, int);
void triShaker(int *, int);
void triGnome(int *, int);
void triPeigne(int *, int);
void triShell(int *, int);

// Les implémentations

void triBulle(int T[], int T1)
{
    int i, j;
    for (i = 0; i < T1 - 1; i++)
    {
        for (j = 0; j < T1 - i - 1; j++)
        {
            if (T[j] > T[j + 1])
            {

                int temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
}

void triSelection(int T[], int T1)
{
    int i, min, j, temp;

    for (i = 0; i < T1 - 1; i++)
    {
        min = i;
        for (j = i; j < T1; j++)
            if (T[j] < T[min])
                min = j;
        temp = T[i];
        T[i] = T[min];
        T[min] = temp;
    }
}

void triInsertion(int T[], int T1)
{

    int i, j, key;
    for (i = 1; i < T1; i++)
    {
        key = T[i];
        j = i - 1;
        while (j >= 0 && T[j] > key)
        {
            T[j + 1] = T[j];
            j = j - 1;
        }
        T[j + 1] = key;
    }
}

void triRapide(int T[], int T1)
{
    int mur, courant, pivot, tmp;
    if (T1 < 2)
        return;

    pivot = T[T1 - 1];
    mur = courant = 0;
    while (courant < T1)
    {
        if (T[courant] <= pivot)
        {
            if (mur != courant)
            {
                tmp = T[courant];
                T[courant] = T[mur];
                T[mur] = tmp;
            }
            mur++;
        }
        courant++;
    }
    triRapide(T, mur - 1);
    triRapide(T + mur, T1 - mur);
}

void fusion(int *a, int n, int m)
{
    int i, j, k;
    int *x = (int *)malloc(sizeof(int) * n);
    for (i = 0, j = m, k = 0; k < n; k++)
    {
        x[k] = j == n        ? a[i++]
               : i == m      ? a[j++]
               : a[j] < a[i] ? a[j++]
                             : a[i++];
    }
    for (i = 0; i < n; i++)
    {
        a[i] = x[i];
    }
    free(x);
}

void triFusion(int T[], int T1)
{
    if (T1 < 2)
        return;
    int milieu = T1 / 2;
    triFusion(T, milieu);
    triFusion(T + milieu, T1 - milieu);
    fusion(T, T1, milieu);
}

void triShaker(int T[], int T1)
{
    int i, j, sens = 1;
    int debut = 0, fin = T1 - 1;
    int permutation;
    do
    {
        permutation = 0;
        if (sens == 1)
        {
            for (i = debut; i < fin; i++)
            {
                if (T[i] > T[i + 1])
                {
                    int temp = T[i];
                    T[i] = T[i + 1];
                    T[i + 1] = temp;
                    permutation = 1;
                }
            }
            fin--;
        }
        else
        {
            for (j = fin; j > debut; j--)
            {
                if (T[j] < T[j - 1])
                {
                    int temp = T[j];
                    T[j] = T[j - 1];
                    T[j - 1] = temp;
                    permutation = 1;
                }
            }
            debut++;
        }
        sens = 1 - sens;
    } while (permutation);
}

void triGnome(int T[], int T1)
{
    int i, j;
    for (i = 1; i < T1;)
    {
        if (T[i] >= T[i - 1])
        {
            i++;
        }
        else
        {
            int temp = T[i];
            T[i] = T[i - 1];
            T[i - 1] = temp;
            if (i > 1)
            {
                i--;
            }
        }
    }
}

void triPeigne(int T[], int T1)
{
    int gap = T1;
    bool permutation = true;

    while (permutation || gap > 1)
    {
        gap = (gap * 10) / 13; // Réduction de l'écart
        if (gap < 1)
            gap = 1;
        permutation = false;

        for (int en_cours = 0; en_cours < T1 - gap; en_cours++)
        {
            if (T[en_cours] > T[en_cours + gap])
            {
                int temp = T[en_cours];
                T[en_cours] = T[en_cours + gap];
                T[en_cours + gap] = temp;
                permutation = true;
            }
        }
    }
}

void triParInsertion(int t[], int gap, int debut, int taille)
{
    int j, en_cours;
    for (int i = gap + debut; i < taille; i += gap)
    {
        en_cours = t[i];
        for (j = i; j >= gap && t[j - gap] > en_cours; j -= gap)
        {
            t[j] = t[j - gap];
        }
        t[j] = en_cours;
    }
}

void triShell(int T[], int T1)
{
    int gap = T1 / 2;
    while (gap > 0)
    {
        for (int i = 0; i < gap; i++)
        {
            triParInsertion(T, gap, i, T1);
        }
        gap /= 2;
    }
}
