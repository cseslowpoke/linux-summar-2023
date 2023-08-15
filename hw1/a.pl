set term png enhanced font 'Andale Mono,10'
set output 'test.png'
# set logscale {n, times}
set xlabel '10^{(n+3)}'
set ylabel 'times'
set title 'test'
# plot with diffrenet color
plot 'tt.txt' using 1:2 title 'my' with linespoints , \
'tt.txt' using 1:3 title 'more bit manipulation' with linespoints, \
