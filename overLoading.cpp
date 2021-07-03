#include<iostream>

using namespace std;

#define MAX 100

class Stack{
    private:
        int top;
    
    public:
        int data[MAX];

        int getTop();
        void setTop(int i);

        bool push(int i);
        int pop();
        bool isEmpty();
        int peek();

        Stack(){
            top = -1;
        }

        ~Stack(){
            cout<<"Destruct"<<endl;
        }
};

bool Stack :: push(int i){
    if(top >= MAX){
        cout<<"Stack Overflow"<<endl;
        return false;
    }

    data[++top] = i;

    return true;
}

bool Stack :: isEmpty(){
    if(top == -1)
        return true;
    
    return false;
}

int Stack :: pop(){
    if(top == -1){
        cout<<"Stack Underflow"<<endl;
        return 0;
    }

    return data[top--];
}

int Stack :: peek(){
    if(isEmpty()){
        cout<<"EMPTY " <<endl;
        return -1;
    }

    return data[top];
}

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "PEEK : " << s.peek() << endl;

    s.pop();
    cout << "PEEK : " << s.peek() << endl;

    s.pop();
    cout << "PEEK : " << s.peek() << endl;

    s.pop();
    cout << "PEEK : " << s.peek() << endl;

    return 0;
}