set xrange [-2:2]
set yrange [-2:2]
set terminal pngcairo color enhanced font ",11"
set xlabel "{/Symbol q}" 
set ylabel "d{/Symbol q}/dt"
set output 'pendulum.png'
l = 4.0
g = 9.80665
phi = 1.02332670795
set parametric
plot sin((g/l)**(1/2)*t+phi), (g/l)**(1/2)*cos((g/l)**(1/2)*t+phi) title "{/Symbol q}-d{/Symbol q}/dt"