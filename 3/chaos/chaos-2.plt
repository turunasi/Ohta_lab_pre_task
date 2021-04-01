set xrange [-6:6]
set yrange [-3:3]
set xlabel "z" 
set ylabel "x"
set terminal png
set output 'chaos-2.png'
set parametric
plot 'chaos-2.txt' using 3:1 with lines title "chaos"