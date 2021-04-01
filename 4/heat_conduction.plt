set xrange [0:1]
set yrange [0:1]
set xlabel "non-dimentional x" 
set ylabel "non-dimentional temperature"
set terminal png
set output 'heat_conduction.png'
plot 'heat_conduction.txt' with points pointsize 0.1 title "heat conduction