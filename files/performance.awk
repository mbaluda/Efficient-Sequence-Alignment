#!/usr/bin/awk -f
BEGIN {
    ORS=" ";
nchar="0";
}
{
    if (NR==1) base=$0;

    if (NR%3==1) {
        print "\n" nchar "\t" $0;
        nchar+=1000;
    }
    else print "\t" $0;
}
END{
print "\n";
}