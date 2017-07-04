#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <list>
#include <algorithm>     //Range

//way to execute: c++ -std=c++11 stack.cpp -o stack && ./stack
using namespace std;

int main(void){

    std::vector<int> v = {11,12,13,14};
    std::list<int> mylist = {11,12,13,14};
    mylist.remove(3);
    mylist.push_front(0);
    mylist.push_back(5);
    mylist.pop_front();
    mylist.pop_back();

    auto itbegin = mylist.begin();
    auto itend = mylist.end();
    auto ritbegin = mylist.rbegin();
    auto ritend = mylist.rend();

    cout << "size of mylist: " << mylist.size() << endl;
    cout << "itbegin:"<< *itbegin << " address:"<< &itbegin<< endl;
    cout << "itend:"<< *itend << " address:" << &itend << endl;
    cout << "ritbegin:"<< *ritbegin << " address:"<< &ritbegin<< endl;
    cout << "ritend:"<< *ritend << " address:" << &ritend << endl;

    std::list<int>::iterator it = mylist.begin();
    std::advance(it, 2);
    int value = 9;
    mylist.insert(it, value);

    auto position = std::distance(it , mylist.begin());
    cout << "position:" << position << endl;

    if (!mylist.empty()){
        cout << "mylist is not empty" << endl;
    }

    for (auto each: mylist){
        cout << each << " ";
    }
    cout<<endl;

    for (auto each: v){
        cout << each << " ";
    }
    cout<<endl;

    return 0;
}
