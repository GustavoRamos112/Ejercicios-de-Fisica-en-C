reset
set terminal pngcairo  transparent enhanced font "arial,9" fontscale 1.0 size 400, 400
set output '10_1.png'
plot "10.txt" u 1:4 w l lt 6 lw 2 title 'Error'
#plot "10.txt" u 1:2 w l lt 4 lw 2 title 'Euler', \
	"10.txt" u 1:3 w l lt 5 lw 2 title 'Runge-Kutta'
