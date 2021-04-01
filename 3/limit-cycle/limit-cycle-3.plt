set xrange [-2:2]
set yrange [-2:2]
set xlabel "x" 
set ylabel "y"
set terminal png
set output 'limit-cycle-3.png'
set parametric
plot 'limit-cycle-3.txt' with lines smooth bezier title "limit-cycle"