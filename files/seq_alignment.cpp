#include <iostream>
#include <stdlib.h>
#include <alibio/two_sequence.hpp>

int main(int argc, char *argv[]){
     cout << "Optimal global alignment (affine gap penalty)" << endl;
     my_alignment.nw_affine_align();
     my_alignment.print_alignment();

    return 0;
}
