#include <algorithm>
#include <iostream>
#include <list>
 
// way to execute this program:
// c++ -std=c++11 sumhashtable.cpp -o sumhashtable && ./sumhashtable
struct arrHashmap{
    int key;
    int value;
};

int main(void){
    
    //sum of two elements in specified array equals the specifed t value of user input
    int arr[] = {-11,-9,10,-8};
    int t = 1;
    
    //linear search to find the largest number in array
    int idx = 0;
    unsigned int arraylength = sizeof(arr) / sizeof(int);

    // Get the largest number in array
    int largestNum = arr[0];

    for (idx = 1; idx < arraylength; idx++){
        if (arr[idx] > largestNum){
            largestNum = arr[idx];
        }
    }
    
    //create hashmap for array 'arr', O(n)
    int id;
    struct arrHashmap hashtable[100] = {0}; //size should be largestNum

    //NOTE: pointer hack if not support VLA, variable length array 
    /*
    int pidx;
    for (pidx = 0; pidx < largestNum; pidx++){
        (p + pidx)->key = 0;
        (p + pidx)->value = 0;
    }
    */

    //Create hashtable for keys and values
    for (id = 0; id < arraylength; id++){
        hashtable[arr[id]].key = arr[id];
        hashtable[arr[id]].value = id;
    }

    //Using hashmap to tackle the two elements sum problem
    int i;
    std::list<int> result;

    for (int i = 0; i< arraylength; i++){
        if ( hashtable[t - arr[i]].key == t - arr[i] ){
            result.push_back(i);
            result.push_back(hashtable[t - arr[i]].value);
        }
    }
    

    //bad: brute-force search for the two elements sum equals t, 
    /*
    int i;
    int j;

    for (i = 0; i < arraylength; i++){
        for (j = i + 1; j < arraylength; j++){
            if (hashtable[i].value + arr[j] == t){
                result.push_back(i);
                result.push_back(j);
            }
        }
    }
    */

    //show all possible combinations
    for (int e: result){
        printf("%d ", e);
    }
}
