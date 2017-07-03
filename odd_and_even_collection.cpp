#include <iostream>
#include <stdlib.h>
#include <list>

// usage:
// c++ -std=c++11 odd_and_even_collection.cpp -o odd_and_even_collection && ./odd_and_even_collection

using namespace std;

struct hashtable{
    unsigned int idx;
    bool isEven;
};

std::list<int> odd_and_even_collection (int arr[], unsigned int arraysize){

    struct hashtable h[arraysize];
    int i = 0;
    int left = 0;
    int right = arraysize;
    std::list<int> result;

    for (i = 0; i < arraysize; i++){
        if (arr[i] % 2  == 0 ){
            result.push_back(i);
        }else{
            result.push_front(i);
        }
    }
    return result;
}

int main(void){
    int arr[]= {2,3,4,5,2,3,1};
    std::list<int> outputlist;

    outputlist = odd_and_even_collection(arr, 7);
    
    for ( auto output: outputlist){
        cout << output << " ";
    }
    cout << endl;

    return 0;
}

