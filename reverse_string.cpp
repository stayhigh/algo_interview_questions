#include <stdio.h>
#include <string.h>

// usage:
// c++ -std=c++11 reverse_string.cpp -o reverse_string && ./reverse_string

int string_length(char *p){
    int c = 0;
    while (*(p + c)){
        c++;
    }

    return c;
}

int main(void){
    char str[] = "hello world";
    unsigned int length = string_length(str);
    char reversed_str[length];
    int offset = 0;

    // necessary to assign '\0' after the last char of reversed_str
    while (offset < length){
        reversed_str[length - 1 - offset] = *(str + offset);
        printf("%c ", *(str+offset));
        offset++;
    } 
    reversed_str[length] = '\0';
    

    printf("%s\n", reversed_str);
    printf("string length of str: %d\n", string_length(str));
    printf("string length of reversed_str: %d\n", string_length(reversed_str));
    return 0;
}
