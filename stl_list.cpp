#include<iostream>
#include<list>

using namespace std;

int main(){
    list<int> v = {1, 2, 3, 4, 5, 6};

    v.push_back(10);
    v.push_back(20);
    v.push_back(40);

    list<int> :: iterator itr;

    for(itr = v.begin(); itr != v.end(); itr++){
        cout << *itr << endl;
    } 

    return 0;
}