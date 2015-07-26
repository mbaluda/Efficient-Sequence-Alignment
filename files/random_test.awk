#!/usr/bin/awk -f
BEGIN {}
{
    if ((NR%16)%2==1) old=$3;
    if ((NR%16)%2==0){
        if (NR%16==2 || NR%16==4){
            if ($4!=old) print old "<-->" $4 " ERRORE NELLA STAMPA " NR%16 "\n";
        }
        else if ($3!=old) print old "<-->" $3 " ERRORE NELLA STAMPA " NR%16 "\n";
    }

    else if (NR%16==5) var5=$3;
    else if (NR%16==7) var7=$3;
    else if (NR%16==9) var9=$3;
    else if (NR%16==11) {
        if ($3!=var5) print var5 "<-->" $3 " GLOBAL\n";
    }
    else if (NR%16==13) {
        if ($3!=var7) print var7 "<-->" $3 " LOCAL\n";
    }
    else if (NR%16==15) {
        if ($3!=var9) print var9 "<-->" $3 " SEMIGLOBAL\n";
    }
}
END{}