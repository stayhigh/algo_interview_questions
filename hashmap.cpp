#include <iostream> // standard IO
#include <map>      // map STL
#include <string.h> // string data type

/* usage: 
   c+ -std=c++11 hashmap.cpp -o hashmap && ./hashmap
*/

using namespace std;

int main(void){
    
    //create a hashmap (CREATE)
    std::map<string, string> ordered_map;
    
    //retrieve all items (key, value), (READ)
    std::map<string, string>::iterator it;
    for (it = ordered_map.begin(); it != ordered_map.end(); ++it){
        cout << "key:"<< it->first << "->value:"<< it->second <<endl;
    }

    //insert items into hashmap (UPDATE)
    //insert: O(log(n))
    //n : size of container
    ordered_map.insert(std::pair<string, string>("k1", "v1"));
    ordered_map.insert(std::pair<string, string>("k2", "v2"));
    ordered_map.insert(std::pair<string, string>("k3", "v3"));
    ordered_map.insert(std::pair<string, string>("k4", "v4"));
    ordered_map["k5"] = "v5";

    //delete an item into hashmap (DELETE), erase by key or range
    //By Range: (from k3 to k5)
    std::map<string, string>::iterator itrange = ordered_map.begin();
    std::advance(itrange, 2);
    ordered_map.erase(itrange, ordered_map.end());
    //By Key: (just k1)
    ordered_map.erase("k1");

    //retrieve all items again (key, value), (READ)
    std::map<string, string>::iterator it2;
    for (it2 = ordered_map.begin(); it2 != ordered_map.end(); ++it2){
        cout << "key:"<< it2->first << "->value:"<< it2->second <<endl;
    }

    //quick items insertion for hashmap
    // find : O(log(n))
    std::map<string, string> qhashmap = {{"qk1", "qv1"}, {"qk2", "qv2"}};
    auto search = qhashmap.find("qk2");
    if (search != qhashmap.end()){
        cout << "found "<< qhashmap["qk2"] << "->" << qhashmap["qk2"] << endl;
    } else {
        cout << "not found" << endl;
    }
    return 0;
}
