#include <iostream>
#include <stdlib.h>
#include <alibio/two_sequence.hpp>

int main(){
    //declaring an alphabet for DNA
    alibio::alphabet dna("DNA");

    //adding symbols to the alphabet
    dna.add_symbol(alibio::symbol('a',"Adenine"));
    dna.add_symbol(alibio::symbol('c',"Citosine"));
    dna.add_symbol(alibio::symbol('t',"Thymine"));
    dna.add_symbol(alibio::symbol('g',"Guanine"));

    //declaring 2 sequences with "bio_string" class as primary structure and
    //"empty" class as secondary and tertiary structures
    alibio::sequence<alibio::bio_string,alibio::empty,alibio::empty> seq_one;
    alibio::sequence<alibio::bio_string,alibio::empty,alibio::empty> seq_two;

    //setting the alphabet (working on "seq_one.primary")
    seq_one.primary.set_alphabet(dna);
    seq_two.primary.set_alphabet(dna);

    //setting the sequence (working on "seq_one.primary")
    seq_one.primary.set_sequence("gaacgcgaatgcctctctctctttcgatgggtatgccaattgtccacattcactcgtgttgcctcctctttgccaacacgcaagacaccagaaacgcgtcaaccaaagagaaaaagacgccgacaacgggcagcactcgcgagagacaaaggttatcgcgttgtgttattatacattcgcatccgggtcaactttagtccgttgaacatgcttcttgaaaacctagttctcttaaaataacgttttagaagttttggtcttcagatgtctgattcgctaaatcatccatcgagttctacggtgcatgcagatgatggattcgagccaccaacatctccggaagacaacaacaaaaaaccgtctttagaacaaattaaacaggaaagagaagcgttgtttacggttagttacctattagctgcaagttttgaaaaagcggaatctgtaaaaagcggaatctgtaaaaaaaacatctaaggaataattctgaaaagaaaaagtttctaaatgttaatcggaatccaatttttatgaaattatttaaaaaaaaactaaaattagtttctaaaaaatttttctaaagtaattggaccatgtgaaggtacacccacttgttccaatatgccatatctaactgtaaaataatttgattctcatgagaatatttttcaggatctattcgcagatcgtcgacgaagcgctcgttctgtgattgaagaagctttccaaaacgaactcatgagtgctgaaccagtccagccaaacgtgccgaatccacattgtgagttggaaatttttatttgataaccaagagaaaaaaagttctacctttttttcaaaaacctttccaaaaatgattccatctgatataggattaagaaaaatattttccgaaatctctgcttttcagcgattcccattcgtttccgtcatcaaccagttgctggacctgctcatgatgttttcggagacgcggtgcattcaatttttcaaaaaataatgtccaggtatacactatttttgcatatttttcttgccaaatttggtcaaaaaccgtagtacaacccaaaaagtttcttcatttcagaggagtgaacgcggattatagtcattggatgtcatattggatcgcgttgggaatcgacaaaaaaacacaaatgaactatcatatgaaaccgttttgcaaagatacttatgcaactgaaggctccttaggtaggttagtcttttctaggcacagaagagtgagaaaattctaaatttctgagcagtctgctttttgttttccttgagtttttacttaaagctcttaaaagaaatctaggcgtgaagttcgagccttgtaccataccacaacagcattccaaatgttacagaagcgaaacaaacatttactgataaaatcaggtcagctgttgaggaaattatctggaagtccgctgaatattgtgatattcttagcgagaagtggacaggaattcatgtgtcggccgaccaactgaaaggtcaaagaaataagcaagaagatcgttttgtggcttatccaaatggacaatacatgaatcgtggacaggttagtgcgaatcggggactcaagatttactgaaatagtgaagagaaaacaaaagaaaactatattttcaaaaaaaatgagaactctaataaacagaatgaaaaacattcaaagctacagtagtatttccagctggagtttccagagccaaaaaaatgcgagtattactgtagttttgaaattggtttctcactttacgtacgattttttgatttttttttcagactcttcatatgaaaaaaaatcatgttttctcctttacaagatttttttgatctcaaaacatttccagagtgacatttcacttcttgcggtgttcgatgggcatggcggacacgagtgctctcaatatgcagctgctcatttctgggaagcatggtccgatgctcaacatcatcattcacaagatatgaaacttgacgaactcctagaaaaggctctagaaacattggacgaaagaatgacagtcagaagtgttcgagaatcttggaaaggtggaaccactgctgtctgctgtgctgttgatttgaacactaatcaaatcgcatttgcctggcttggagattcaccagggtaatcaatttttttttagtttttggaactttacgtcccgaaaaattattcctttatcacctaattcctacagtaacccaagctccgaattaaataaagttaaagcgtggtatacacataaaaataagaaaaaattgttcatgaaatccatttttccagttacatcatgtcaaacttggagttccgcaaattcactactgaacactccccgtctgacccggaggaatgtcgacgagtcgaagaagtcggtggccagatttttgtgatcggtggtgagctccgtgtgaatggagtactcaacctgacgcgagcactaggagacgtacctggaagaccaatgatatccaacaaacctgataccttactgaagacgatcgaacctgcggattatcttgttttgttggcctgtgacgggatttctgacgtcttcaacactagtgatttgtacaatttggttcaggcttttgtcaatgaatatgacgtagaaggtatcaaactgatcgtttttcacatcacaaaattcttgaattttccagattatcacgaacttgcacgctacatttgcaatcaagcagtttcagctggaagtgctgacaatgtgacagtagttataggtttcctccgtccaccagaagacgtttggcgtgtaatgaaaacagactcggatgatgaagagagcgagctcgaggaagaagatgacaatgaatagtttattgcaagttttccaaaacttttccaatttccctgggtattgattagcatccatatcttacggcgattatatcaattgtaacattatttctgtttctccccccacctctcaaattttcaaatgaccctttttcttttcgtctacctgtatcgttttccattcatctccccccctccactgtggtatatcattttgtcattagaaagtattattttgattttcattggcagtagaagacaacaggatacagaagaggttttcacag");

    //setting the sequence (working on "seq_two.primary")
    seq_two.primary.set_sequence("ggtagaacagcttcagttgggatcacaggcttctagggatcctttgggcaaaaaagaaacacagaaggcattctttctatacaagaaaggactttatagagctgctaccatgaacggaacagaaggtccaaatttttatgtccccatgtccaacaaaactggggtggtacgaagcccattcgattaccctcagtattacttagcagagccatggcaatattcagcactggctgcttacatgttcctgctcatcctgcttgggttaccaatcaacttcatgaccttgtttgttaccatccagcacaagaaactcagaacacccctaaactacatcctgctgaacctggtatttgccaatcacttcatggtcctgtgtgggttcacggtgacaatgtacacctcaatgcacggctacttcatctttggccaaactggttgctacattgaaggcttctttgctacacttggtggtgaagtggccctctggtcactggtagtattggccgttgaaagatatatggtggtctgcaagcccatggccaacttccgattcggggagaaccatgctattatgggtgtagccttcacatggatcatggctttgtcttgtgctgctcctcctctcttcggatggtccagatacatcccagagggaatgcaatgctcatgcggagtagactactacacactgaagcctgaggtcaacaatgaatcctttgttatctacatgttcattgtccacttcaccattcccctgattgtcatcttcttctgctatggtcgcctgctctgcactgtcaaagaggctgcagcccagcaacaggaatctgctaccacccagaaggctgagaaagaggtcaccagaatggttgttatcatggtcgttttcttcctgatctgttgggtgccctatgcctatgtggcattctacatcttcacccaccagggctctaactttggcccagtcttcatgaccgtcccagctttctttgccaagagctctgctatctacaatcctgtcatctacattgtcttgaacaaacagttccgtaactgcttgatcaccaccctgtgctgtggaaagaatccattcggtgatgaagatggctcctctgcagccacctccaagacagaagcttcttctgtctcttccagccaggtgtctcctgcataagagcttcaccagggctgtctcagggtccgctgcctcacacaattcccatcacttaagccctgtctacttgttgcgaaggcaaagaattccacagttttaatatttacccccattctgcccaaccttggacactgtaagagctgaccccattactgctgggaaggcccaagctttgttgcattctgatgtgatcctttcagcagaaaatgggtggattcaatgaatttcaccaaggctgtacataacaataacattagtctgaaggcacctcccacccagagaatgcaacacttatttatctctgtcttttcttgacatattgatgctgcttctattcatggtcactaacaaaaagtcccattttacaatgcaactgaaagtaatgtatttttgtaatataataacatatttcatgcaatctcctctgcttattggcaaggtctgatatagtgaggatagacagccagaccccttgcattaaaatcctgtattaaaaatttctttgcaagt");

    alibio::score_matrix<int> myscores(dna);

    //modifying the score_matrix
    myscores.set_match_score(5);
    myscores.set_mismatch_score(-4);
    //modifying the score_matrix
    myscores.set_gap_cost(10,1);

    //creating alignment object
    alibio::seq_alignment<int> my_alignment(myscores,
                                              seq_one.primary, seq_two.primary);



    cout << "Optimal global alignment (affine gap penalty)\n";
    my_alignment.semiglobal_affine_align();
    my_alignment.print_alignment();

    return 0;
}