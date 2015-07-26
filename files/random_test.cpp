//ALiBio: Algorithms Library for Bioinformatics
//Copyright (C) 2002-2003:
//Gianluca Della Vedova, Riccardo Dondi, Luca Fossati,
//Lorenzo Mariani, Francesco Rossi.
//
//This library is free software; you can redistribute it and/or
//modify it under the terms of the GNU Lesser General Public
//License as published by the Free Software Foundation; either
//version 2.1 of the License, or (at your option) any later version.
//
//This library is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//Lesser General Public License for more details.
//
//You should have received a copy of the GNU Lesser General Public
//License along with this library; if not, write to the Free Software
//Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
//
//http://bioinformatics.org/ALiBio
//
//Lab. Bioinformatica
//DISCo, Univ. Milano-Bicocca
//via Bicocca degli Arcimboldi 8
//20126 Milano (Italy)

#include <iostream>
#include <stdlib.h>
#include <alibio/two_sequence.hpp>

int main(){

    int alph_size=4;
    int repetitions=2000;
    int max_seq_length=30;

    //Getting internal clock time for random
    srand(time(NULL));

    //declaring an alphabet
    alibio::alphabet my_alph("my alphabet");
    //adding symbols to the alphabet
    for (int i=0; i<alph_size; i++){
        my_alph.add_symbol(alibio::symbol('A'+i));
    }
    alibio::score_matrix<> myscores(my_alph);

    myscores.set_match_score(5);
    myscores.set_mismatch_score(-4);
    myscores.set_gap_cost(10, 0.5);

    for (int k=0;k<repetitions;k++){
        vector<char> fst, snd;
        int n=rand() % max_seq_length;
        int m=rand() % max_seq_length;
        
        fst.reserve(n);
        snd.reserve(m);

        //generating strings randomly
        for (int i=0; i<n; i++){
            fst.push_back('A'+(rand() % alph_size));
            cout << fst[i];
        }
        cout << endl;
        for (int j=0; j<m; j++){
            snd.push_back('A'+(rand() % alph_size));
            cout << snd[j];
        }
        cout << endl;

        //creating the alignment matrix
        alibio::seq_alignment<> my_alignment(myscores, fst , snd);

        //do the alignment
        cout << "Optimal global alignment (linear gap penalty)" << endl;
        my_alignment.nw_align();
        my_alignment.print_alignment();

        cout << "Optimal local alignment (linear gap penalty)" << endl;
        my_alignment.sw_align();
        my_alignment.print_alignment();

        
        
        cout << "Optimal global alignment (affine gap penalty)" << endl;
        my_alignment.nw_affine_align();
        my_alignment.print_alignment();
        
        cout << "Optimal local aligment (affine gap penalty)" << endl;
        my_alignment.sw_affine_align();
        my_alignment.print_alignment();

        cout << "Optimal semiglobal alignment (affine gap penalty)" << endl;
        my_alignment.semiglobal_affine_align();
        my_alignment.print_alignment();

        
                
        cout << "Optimal global aligment (affine gap penalty - linear space)" << endl;
        my_alignment.nw_linear_align();
        my_alignment.print_alignment();
        
        cout << "Optimal local aligment (affine gap penalty - linear space)" << endl;
        my_alignment.sw_linear_align();
        my_alignment.print_alignment();

        cout << "Optimal semiglobal aligment (affine gap penalty - linear space)" << endl;
        my_alignment.semiglobal_linear_align();
        my_alignment.print_alignment();
    }
        
    return 0;
}
