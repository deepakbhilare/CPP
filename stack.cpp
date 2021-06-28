#include<iostream>

#define MAX 100
using namespace std;

class stack{
    private:
        int top;

    public:
        int a[MAX];

        stack(){
            top = -1;
        }

        int pop();
        bool push(int x);
        bool isEmpty();
        bool isFull();
};

bool stack :: push(int x){
    if(top >= MAX - 1){
        cout << "Stack overflow" << endl;
        return false;
    }
    else{
        cout<<"inserted " << x << endl;
        a[++top] = x;
    }

    return true;
}

int stack :: pop(){
    if(isEmpty()) {
        cout<<"stack empty"<<endl;
        return false;
    }
    else{
        cout<<"pop : " << a[top] << endl;
        top--;
    }

    return a[top];
}

bool stack :: isEmpty(){
    if(top == -1){
        cout << "stack empty" << endl;
        return true;
    }

    return false;
}

bool stack :: isFull(){
    if(top >= MAX){
        cout<<"stack full" << endl;
        return true;
    }

    return false;
}

int main(){
    stack s;
    s.push(10);
    s.push(100);
    s.push(3);

    cout<<"POP :" << s.pop() << endl;
    cout<<"POP :" << s.pop() << endl;
    cout<<"POP :" << s.pop() << endl;
    cout<<"POP :" << s.pop() << endl;


    return 0;
}