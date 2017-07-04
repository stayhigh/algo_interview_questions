#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// usage:
// c++ -std=c++11 reverse_string.cpp -o reverse_string && ./reverse_string

int string_length(char *p){
    int c = 0;
    while (*(p + c)){
        c++;
    }
    return c;
}

//need extra dynamic memory allocation for reversed string
char* reverse(char *str){
    int offset = 0;
    unsigned int length = string_length(str);
    char *reversed_str = (char *) malloc(length * sizeof(char) + 1);

    // necessary to assign '\0' after the last char of reversed_str
    while (offset < length){
        *(reversed_str + length - 1 - offset) = *(str + offset);
        offset++;
    } 

    reversed_str[length] = '\0';

    return reversed_str;
}

//efficient reverse
char* reverse_2(char *str){
    int length = string_length(str);
    int mid = length / 2;
    int p;
    int delta = (length % 2 == 0) ? 0:1; 
    char *left = str + mid - 1;
    char *right = str + mid + delta;
    char tmp;

    /* deal with special cases*/
    if (length == 1 or str == NULL)
        return str;

    /* odd and even chars cases */
    for (p = mid; p < length; p++){
        //swap left and right char
        printf("left: %c , right: %c\n", *left, *right);
        tmp = *right;
        *right = *left;
        *left = tmp;

        left--;
        right++;
    }

    return str;
}

int main(void){

    /* odd chars */
    char oddstr[] = "hello world";
    char *odd_reversed_str2 = reverse_2(oddstr);
    printf("reverse(oddstr) => %s\n", odd_reversed_str2);

    /* even chars */
    char evenstr[] = "johnwang";
    char *even_reversed_str2 = reverse_2(evenstr);
    printf("reverse(evenstr) => %s\n", even_reversed_str2);

    return 0;
}
