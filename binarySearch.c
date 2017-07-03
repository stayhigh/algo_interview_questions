#include <stdio.h>
#include <stdlib.h>

//usage: cc binarySearch.c -o binarySearch && ./binarySearch
//
int binarySearch(int arr[], int lowerbound, int upperbound, int item){
    unsigned int mid = (upperbound - lowerbound) / 2;

    while (arr[mid] != item){
        mid = lowerbound + (upperbound - lowerbound) / 2;
        printf("mid:%d, lowerbound:%d, upperbound:%d\n", mid, lowerbound, upperbound);
        if (upperbound < lowerbound){
            printf("%s\n","not found\n");
            mid = -1;
            break;
        } else if (arr[mid] == item ){
            printf("found at pos: %d\n", mid);
            break;
        } else if (arr[mid] > item){
            upperbound = mid - 1;
        } else if (arr[mid] < item){
            lowerbound = mid + 1;
        }
    }

    return mid;
}

int main(void){

#define MAX 10
    int array[MAX] = {1,2,3,4,5,6,7,8,9,10};
    int result = -1;
    result =  binarySearch(array, 0, MAX - 1, 7);
    printf("result: %d\n", result);
    return 0;
}

