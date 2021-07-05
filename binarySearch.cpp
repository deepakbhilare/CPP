#include<iostream>

using namespace std;

int binarySearch(int *arr, int n, int search){
    int start = 0;
    int end = n - 1;
    int count = 0;


    while(start <= end){
        cout <<"COUNT : " << count++ << endl;
        int mid = (start + end) / 2;

        if(arr[mid] == search)
            return mid;
        else if(arr[mid] < search)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main(){
    int arr[] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 300, 310, 311, 312, 500, 501};

    int n = 18;
    int search = -501;

    int index = binarySearch(arr, n, search);

    if(index > 0)
        cout << "Element at : " << index << endl;
    else 
        cout << "Element not found" << endl;

    return 0;
}