set xrange [-70:70]
set yrange [-70:70]
set xlabel "y" 
set ylabel "z"
set terminal png
set output 'chaos-3.png'
set parametric
plot 'chaos-3.txt' using 2:3 with lines title "chaos"