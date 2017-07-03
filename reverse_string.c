#include <stdio.h>
#include <string.h>

int main(void){
    char *str = "hello world";
    unsigned int length = strlen(str);
    char reversed_str[length];
    int c = 0;

    while (c < length){
        reversed_str[length - 1 - c] = *(str + c);
        c++;
    } 

    printf("%d\n", length);
    printf("%s\n", reversed_str);
    return 0;
}
