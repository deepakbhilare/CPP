#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v ;//= {1, 2, 3, 4, 5, 6};

    v.push_back(10);
    v.push_back(20);
    v.push_back(40);

    vector<int> :: iterator itr;

    for(itr = v.begin(); itr != v.end(); itr++){
        cout << *itr << endl;
    } 

    return 0;
}