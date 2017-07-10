#include <iostream>


using namespace std;

int re_parse(char* str, char* pattern){
    int i;
    int j;
    int match = -1;
    int cnt = 0;

    char *nextchar = NULL;
    char *nextpatternchar = NULL;

    /* engine for question mark */
    for (i = 0, j = 0; i < strlen(str); i++, j++) {
        cout << "i:" << i << " j:" << j <<endl; 
        if (*(pattern + j) == '?'){
            continue;
        } else if  (*(pattern + j) == '*') {
            j++;
            nextpatternchar = pattern + j;
            while (1){
                i++;
                nextchar = str + i;
                if (*nextchar == *nextpatternchar) {
                    match = 1;
                    break;
                } else if (*nextchar != * nextpatternchar) {
                    nextchar++;
                } else if (*nextchar == '\0') {
                    match = 0;
                    break;
                }
            } 
        } else if (*(str + i) != *(pattern + j) ) {
            match = 0;
            break;
        } else if ( i == strlen(str) - 1 ) {
            match = 1;
        }        
    }
    return match;
}

int main(void){
    // warning: ISO C++11 does not allow conversion from string literal to 'char *' [-Wwritable-strings]
    // declare array-like strings
    char target[] = "hello";
    char pattern[] = "?e?lo";
    char pattern2[] = "*llo";
    char pattern3[] = "h*l?o";
    char pattern4[] = "h*lo";

    int match = re_parse(target, pattern);
    if (match) {
        printf("pattern matched.\n");
    }

    int match2 = re_parse(target, pattern2);
    if (match2) {
        printf("pattern2 matched.\n");
    }

    int match3 = re_parse(target, pattern3);
    if (match3) {
        printf("pattern3 matched.\n");
    }

    int match4 = re_parse(target, pattern4);
    if (match4) {
        printf("pattern4 matched.\n");
    } else {
        printf("pattern4 NOT matched.\n");
    }

    return 0;
}
