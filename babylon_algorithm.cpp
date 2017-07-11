#include<iostream>

using namespace std;

/* How to calculate the square root of n 
 *
 * 1. choose n/2 as first guess
 * 2. r = n / guess, gnd guess = ( guess + r ) / 2
 * 3. repeat the procedure 1 and 2 until reaching the stop condition
 *
 * */

int babylon_algo(int n, int round){
    float guess = n / 2;
    float r;
    int i;

    for (i = 0; i < round; i++){
        r = n / guess;
        guess = (guess + r) / 2;
        cout << "round: " << i << " square root: " << guess << endl;
    }

    return guess;
}

int main(void){
    float square_root = babylon_algo(7, 50);
    return 0;
}
