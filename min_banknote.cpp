#include <iostream>
#include <list>

using namespace std;

int main(void){
    std::list<int> denomination = {100, 50, 20, 10, 5, 1};
    std::list<int>::iterator it;
    int cnt = 0;
    int rest = 0;
    int n = 999; // n (from 0 - 1000)
    
    for (it = denomination.begin();it != denomination.end() ; it++){
        cnt += n / *it;
        rest = n % *it;
        n = rest;
    }

    cout << "cnt: " << cnt << endl;

    return 0;
}
