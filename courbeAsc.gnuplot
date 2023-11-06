set title "Title: Courbe de complexite des Algos de Trie avec Des Valeurs Triee Croissant"
set xlabel "X: Longueur des tableaux"
set ylabel "Y: Temps (en ms)"

set style line 1 lt 1 linecolor rgb "red" lw 2 pt 1
set style line 2 lt 1 linecolor rgb "black" lw 2 pt 1
set style line 3 lt 1 linecolor rgb "purple" lw 2 pt 1
set style line 4 lt 1 linecolor rgb "yellow" lw 2 pt 1
set style line 5 lt 1 linecolor rgb "blue" lw 2 pt 1
set style line 6 lt 1 linecolor rgb "brown" lw 2 pt 1
set style line 7 lt 1 linecolor rgb "green" lw 2 pt 1
set style line 8 lt 1 linecolor rgb "magenta" lw 2 pt 1
set style line 9 lt 1 linecolor rgb "orange" lw 2 pt 1

set datafile separator ","
set grid

set term png  # Set the terminal to output to a PNG file
set output "output_Courbe_Asc.png"  # Set the output file name

plot "bulleCSV.csv" using 1:2 ls 1 title "Bulle" with lines , \
     "insertionCSV.csv" using 1:2 ls 2 title "Insertion" with lines , \
     "selectionCSV.csv" using 1:2 ls 3 title "Selection" with lines , \
     "fusionCSV.csv" using 1:2 ls 4 title "Fusion" with lines , \
     "rapideCSV.csv" using 1:2 ls 5 title "Rapide" with lines , \
     "shakerCSV.csv" using 1:2 ls 6 title "Shaker" with lines , \
     "gnomeCSV.csv" using 1:2 ls 7 title "Gnome" with lines , \
     "peigneCSV.csv" using 1:2 ls 8 title "Peigne" with lines , \
     "shellCSV.csv" using 1:2 ls 9 title "Shell" with lines 

set output  # Reset the output to the default (interactive)

#smooth sbezier
