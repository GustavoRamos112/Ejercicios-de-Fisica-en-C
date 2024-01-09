reset
set terminal pngcairo  transparent enhanced font "arial,9" fontscale 1.0 size 600, 400
set output '1.png'
set title 'Metodo de Euler'
set xlabel 't'
set ylabel 'x(t)'
plot [0:1.1] 'datosE.dat' u 1:2 w l title 'Solucion numerica', 'datosE.dat' u 1:3 w l title 'Solucion analitica'
#plot [0:1.1] 'datosK.dat' u 1:2 w l lt 4 lw 2 title 'Solucion numerica', 'datosK.dat' u 1:3 w l lt 3 lw 1 title 'Solucion analitica'
#plot [0:1.1] [-0.01:0.14] 'datosE.dat' u 1:4 w l lt 6 title 'Error Euler', 'datosK.dat' u 1:4 w l lt 5 title 'Error Runge-Kutta'