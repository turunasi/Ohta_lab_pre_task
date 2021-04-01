set term pngcairo size 1280, 1280 font ",11"
set output "joukowski.png"
set multiplot layout 3,3
set xrange [-2:2]
set yrange [-2:2]
set xlabel "x" 
set ylabel "y"
plot 'data/joukowski_1.txt' with lines smooth bezier title "joukowski 1"
plot 'data/joukowski_2.txt' with lines smooth bezier title "joukowski 2"
plot 'data/joukowski_3.txt' with lines smooth bezier title "joukowski 3"
plot 'data/joukowski_4.txt' with lines smooth bezier title "joukowski 4"
plot 'data/joukowski_5.txt' with lines smooth bezier title "joukowski 5"
plot 'data/joukowski_6.txt' with lines smooth bezier title "joukowski 6"
plot 'data/joukowski_7.txt' with lines smooth bezier title "joukowski 7"
plot 'data/joukowski_8.txt' with lines smooth bezier title "joukowski 8"
plot 'data/joukowski_9.txt' with lines smooth bezier title "joukowski 9"
unset multiplot
unset output