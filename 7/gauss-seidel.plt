set output 'gauss-seidel.png'
set xrange [-1:16]
set yrange [-1:6]
set zrange [-1:27]
set xlabel "x" 
set ylabel "y"
set zlabel "z"
set terminal png
set contour
set nosurface
set view 0,0
set cntrparam levels incremental 0, 5, 25
splot 'gauss-seidel.txt' with lines title "gauss-seidel"