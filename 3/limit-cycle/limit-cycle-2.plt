set xrange [-2:2]
set yrange [-2:2]
set xlabel "x" 
set ylabel "y"
set terminal png
set output 'limit-cycle-2.png'
set parametric
plot 'limit-cycle-2.txt' with lines smooth bezier title "limit-cycle"