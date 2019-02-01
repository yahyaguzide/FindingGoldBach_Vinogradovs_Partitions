#include <iostream>
#include <vector>

//////////////////////////////////////////////////////////////////
//  Book: Number Theory for Computing                           //
//  Author: Song Y. Yan                                         //
//                                                              //
//  This algorythm is a Solution to the Exercise 1.1            //
//                                                              //
//  The Goldbach conjecture:                                    //
//      Every even Number can be expressed as the sum of Two    //
//      Prime Numbers                                           //
//  Vinogradov's Three prime theorem:                           //
//      Every odd Number can be written as the sum of           //
//      Three odd Prime Numbers                                 //
//                                                              //
//  Be G(n) the Goldbach Partition of n and |G(n)| the Number   //
//  of Partitions,                                              //
//                                                              //
//  Problem: find all Partitions of 1000 and 1001               //
//      where all Primes in the sum must be Different to        //
//      each other.                                             //
//////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////
//  this is a Vector which holds all Prime Numbers between
//  1 and 1000, this will help us find all 2( for even Numbers)
//  or 3( for odd Numbers) Sum
std::vector<int> primes1_1000 = {
    2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41,
    43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97, 101,

    103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
    173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,

    241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
    317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,

    401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
    479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569,

    571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
    647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733,

    739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823,
    827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,

    919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

//################# Class Partition ####################
////////////////////////////////////////////////
// this will hold one Partition
// we only can have two or 3 number Partitions
struct Partition{
    Partition( int a, int b): NumOfSummands(2){
        int_vec = {a, b};
    };

    Partition( int a, int b, int c): NumOfSummands(3){
        int_vec = {a, b, c};
    };


    // print simply will display one Partition as Follows
    //      3+97
    //      17+83
    //.......
    void print(){

        std::cout << int_vec[0];
        for( int i = 1; i < int_vec.size(); i += 1 ){
            std::cout << "+" << int_vec[i];
        }
        std::cout << "\n";
    }

    std::vector<int>& get_Summands(){ return int_vec; };
    int get_NumOfSummands() { return NumOfSummands; };

private:
    int NumOfSummands;
    std::vector<int> int_vec;
};
//##########################################################

////////////////////////////////////////////////////////////////
// Iterates through all indexes and if findPartitions
// finds a Partition it saves it in a Vector as Partition type
// see: Struct Partition
std::vector<Partition> findPartitions( int Num ){
    // check if Num is odd
    // Cpp will see 0 as False and everythin above 0 as true
    bool odd = Num%2;

    // this Vector hold Partition which hold int Vectors
    std::vector<Partition> tmp_Vec;

    if( odd ){

        // check if we have a Partition
        // We only need to loop vector.size()-2 time for i
        // and vector.size()-2 for j
        // we don't need to look for i = vector.size()-1 because there is no
        // second or Third prime in vector left
        // we only have a machine with a Finite Memory -_o_-
        for( int i = 0; i < primes1_1000.size() -2; i+= 1){
            int j = i+1;
            for( ; j < primes1_1000.size() -1; j+= 1 ){
                int k = j+1;
                for( ; k < primes1_1000.size(); k+= 1 ){
                    if( Num == primes1_1000[i] + primes1_1000[j] + primes1_1000[k] ){
                        tmp_Vec.push_back( Partition( primes1_1000[i], primes1_1000[j], primes1_1000[k] ) );
                    }
                }
            }
        }

    }else{

        // check if we have a Partition
        // like above we only need to loop for vector.size()-1 times
        // because if i is at vector.size()-2 j will be at vector.size()-1
        // we don't need to look for i = vector.size()-1 because there is no
        // second prime in vector left
        // we only have a machine with a Finite Memory -_o_-
        for( int i = 0; i < primes1_1000.size() -1; i+= 1){
                int j = i+1;
            for( ; j < primes1_1000.size(); j+= 1 ){
                if( Num == primes1_1000[i] + primes1_1000[j] ){
                    tmp_Vec.push_back( Partition( primes1_1000[i], primes1_1000[j] ) );
                }
            }
        }
    }

    return tmp_Vec;
}

int main()
{
    // calculate 1001 and compare it to 1001
    int Num = 1000;

    std::vector<Partition> Vec = findPartitions( Num );

    for( int i = 0; i < Vec.size(); i+= 1 ){
        Vec[i].print();
    }

    std::cout << "|G(" << Num << ")| = " << Vec.size();


    return 0;
}
