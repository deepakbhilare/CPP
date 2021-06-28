#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ofstream outFile("myfile.txt", ios::app);

    outFile << "Hello" << endl;
    outFile << 10 << endl;

    outFile.close();

    ifstream inFile;
    inFile.open("myfile.txt");

    if(!inFile.is_open()) {
        cout<< "file not opened";

        return 1;
    }

    string x;
    int i;

    inFile>>x>>i;

    cout << x << " " << i << endl;

    if(inFile.eof()) cout << "file end reached" << endl;

    inFile.close();

    return 0;
}