#include <iostream>


using namespace std;

int re_parse(const char* str, const char* pattern){
    int i;
    int j;
    int match = -1;
    int cnt = 0;

    /* engine for question mark */
    for (i = 0, j = 0; i < strlen(str); i++, j++){
        cout << "i:" << i << " j:" << j <<endl; 
            if (*(pattern + j) == '?'){
                continue;
            } else if (*(str + i) != *(pattern + j) ){
                match = 0;
                break;
            } else if ( i == strlen(str) - 1 ){
                match = 1;
            }
    }

    return match;
}

int main(void){
    const char *target = "hello";
    const char *pattern = "?e?lo";
    int match = re_parse(target, pattern);
    cout << match << endl;
    if (match) {
        printf("pattern matched.");
    }

    return 0;
}
