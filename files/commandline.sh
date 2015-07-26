#!/bin/sh
make libs
g++ -g -pg -Wall -O0 -I ./include sequence_alignment/performance.cpp  -o sequence_alignment/performance.bin
./performance.bin
gprof ./performance.bin > prof.txt
valgrind --tool=massif ./performance.bin
valgrind --leak-check=yes ./performance.bin
gnuplot gnuplot_time.txt
gnuplot gnuplot_space.txt
gnuplot gnuplot_time_compl.txt

cat ../time.dat | ./performance.awk > gnuplot_time.dat
cat ../space.dat |./performance.awk > gnuplot_space.dat
gnuplot gnuplot_time.txt gnuplot_space.txt gnuplot_time_compl.txt gnuplot_space_compl.txt