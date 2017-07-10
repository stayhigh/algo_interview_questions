#include <iostream>
#include <list>

using namespace std;

int get_num_length(int x){
    int length = 0;
    while (x / 10 != 0){
        x = x / 10;
        length++;
    }
    length++;
    return length;
}

int getlastdigit(int *x){
    int ret;
    int lastdigit;
    static int end = 0;

    if (end == 1){
        lastdigit = -1;
        end = 0;
    } else if (*x / 10 != 0){
        lastdigit = *x % 10;
        *x = *x / 10;
        cout << "getlastdigit: lastdigit:" << lastdigit << " *x:" << *x << endl;
    } else if (0 <= *x && *x<= 9){
        lastdigit = *x ;
        end = 1;
        cout << "getlastdigit: ->lastdigit:" <<lastdigit << endl;
    }

    return lastdigit;
}

int reverse_num(int x){
    // expect the output are 54321 and -98765, respectively.
    int last_digit;
    int r;
    int level = 1;
    int out = 0;
    int positive;
    std::list<int> numList;
    std::list<int>::iterator it;

    if (x < 0){
        x = -x;
        positive = 0;
    }

    int i;
    while ((r = getlastdigit(&x)) != -1 ){
        numList.push_front(r);
    }

    for (it = numList.begin(); it != numList.end(); it++){
        out += (*it) * level;
        level *= 10;
    }

    cout << "reverse_num: x->" << x << endl;
    cout << "reverse_num: out->" << out << endl;
    return (positive) ?out:-out;
}

int main(void){
    int num = 12345;
    int num2 = -56789;
    int reversed_num = reverse_num(num);
    int reversed_num_2 = reverse_num(num2);

    cout << "reversed_num  :" << reversed_num << endl;
    cout << "reversed_num_2:" << reversed_num_2 << endl;

    return 0;
}
