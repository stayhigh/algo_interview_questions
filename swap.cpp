#include <iostream>

void swap(int *a, int *b);

using namespace std;

int main(void){

    int a = 1;
    int b = 2;
    swap(&a, &b);
    cout << "a:"<< a << " b:"<< b << endl;
}

void swap(int *a, int *b){
    // bit hack
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

    //addition and substraction
    /*
    *a = *a + *b
    *b = *a - *b
    *a = *a - *b
    */

    //multiplication and division
    /*
    *a = *a * *b
    *b = *a / *b
    *a = *a / *b
    */

}
