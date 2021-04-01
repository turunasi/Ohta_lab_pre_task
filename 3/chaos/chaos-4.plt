set xrange [-2:2]
set yrange [-2:2]
set xlabel "y" 
set ylabel "x"
set terminal png
set output 'chaos-4.png'
set parametric
plot 'chaos-4.txt' using 2:1 with lines title "chaos"