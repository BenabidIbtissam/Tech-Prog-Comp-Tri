# Comparaison des Algorithmes de Tri en C

Ce projet implémente divers algorithmes de tri en C et analyse leur complexité temporelle pour comparer leurs performances.

## Structure des Fichiers

- `main.c` : Le programme principal qui génère des données, effectue des tris et analyse la complexité.
- `methodetri.h` : Fichier d'en-tête contenant les implémentations __des algorithmes de tri__.
- `calcul.h` : Fichier d'en-tête contenant __remplissage du tableau__, __stockage temps dans fichiers CSV__, __execution script GNUplot__
- `courbeAleatoire.gnuplot` : Script Gnuplot pour générer des graphiques basés sur les données __*Aleatoire*__.
- `courbeAsc.gnuplot` : Script Gnuplot pour générer des graphiques basés sur les données __*Triage Croissant*__.
- `courbeDesc.gnuplot` : Script Gnuplot pour générer des graphiques basés sur les données __*Traige Decroissant*__.

## Compilation et Exécution

1. Assurez-vous d'avoir `gcc` et `gnuplot` installés sur votre système.
2. Compilez le programme en exécutant :

   ```bash
   gcc -o execution main.c

3. Exécutez le programme :

    ```bash
    ./execution

4. Le programme générera des données en des fichiers `.CSV` et tracera les graphiques suivantes à l'aide de gnuplot:
    - output_Courbe_Aleatoire.png
    - output_Courbe_Asc.png
    - output_Courbe_Desc.png

### Algorithmes de Tri

- Tri à Bulles
- Tri par Sélection
- Tri par Insertion
- Tri Rapide
- Tri Fusion
- Tri Shaker
- Tri Gnome
- Tri Peigne
- Tri Shell

### Analyse des Données

Le programme génère des données aléatoires et applique divers algorithmes de tri pour mesurer leur temps d'exécution. La complexité temporelle est enregistrée et ultérieurement tracée pour analyser et comparer les performances des algorithmes.

### Tracé des Graphiques
Les graphiques sont générés à l'aide des `scripts Gnuplot`. Les scripts lit les données à partir de fichiers CSV et trace des graphiques de complexité temporelle pour différents algorithmes de tri.

### Résultats

![Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Aleatoire](output_Courbe_Aleatoire.png)\
___Figure : Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Aleatoire___

![Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Asc](output_Courbe_Asc.png)\
___Figure : Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Asc___

![Courbe qui Represente la complexite des differents Algorithmes de Trie](output_Courbe_Desc.png)\
___Figure : Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Desc___

### Références
    
<a href="https://gnuplot.sourceforge.io/">Visit Gnuplot</a>

### Auteur

Ibtissam BENABID\
[![GitHub Badge](https://img.shields.io/badge/GitHub-Profile-brightgreen?style=flat&logo=github&logoColor=white)](https://github.com/IbtissemeBENEBID)
[![LinkedIn Badge](https://img.shields.io/badge/LinkedIn-Connect-blue?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ibtissam-benabid/)






