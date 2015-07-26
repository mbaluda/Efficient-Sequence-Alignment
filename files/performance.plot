#!/usr/bin/gnuplot

set terminal postscript eps enhanced color
set xlabel "Input size (chars)"

    set out 'gnuplot_time.eps'
        set ylabel "Time (sec)"
        set title "Time performance"
        plot \
            'gnuplot_time.dat' using 1:2 title 'nw align' \
                               smooth csplines lt 1 linewidth 3, \
            'gnuplot_time.dat' using 1:3 title 'nw affine align' \
                               smooth csplines lt 2 linewidth 3, \
            'gnuplot_time.dat' using 1:4 title 'nw linear align' \
                               smooth csplines lt 3 linewidth 3

    set out 'gnuplot_space.eps'
        set ylabel "Space (Bytes)"
        set format y "%.0s{/Symbol \327}10^{%S}"
        set title "Space performance"
        plot \
            'gnuplot_space.dat' using 1:2 title 'nw align' \
                                smooth csplines lt 1 linewidth 3, \
            'gnuplot_space.dat' using 1:3 title 'nw affine align' \
                                smooth csplines lt 2 linewidth 3, \
            'gnuplot_space.dat' using 1:4 title 'nw linear align' \
                                smooth csplines lt 3 linewidth 3

set logscale xy
set xtics (1000,1500,2000,2500,3000)

    set out 'gnuplot_time_compl.eps'
        set ylabel "Time (sec)"
        set format y "10^{%L}"
        set title "Time complexity (log axes)"
        plot [1000:] \
            'gnuplot_time.dat' using 1:2 title 'nw align' \
                               smooth csplines lt 1 linewidth 3, \
            'gnuplot_time.dat' using 1:3 title 'nw affine align' \
                               smooth csplines lt 2 linewidth 3, \
            'gnuplot_time.dat' using 1:4 title 'nw linear align' \
                               smooth csplines lt 3 linewidth 3, \
            (x**2)/100000 title 'quadratic' smooth csplines lt -1

    set out 'gnuplot_space_compl.eps'
        set ylabel "Space (Bytes)"
        set format y "%.0s{/Symbol \327}10^{%S}"
        set title "Space complexity (log axes)"
        plot [1000:3000][:500000000] \
            'gnuplot_space.dat' using 1:2 title 'nw align'\
                                smooth csplines lt 1 lw 3,\
            'gnuplot_space.dat' using 1:3 title 'nw affine align' \
                                smooth csplines lt 2 lw 3, \
            x**2 title 'quadratic' smooth csplines lt -1