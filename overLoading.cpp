#include<iostream>

using namespace std;

#define MAX 100

template <class T> 
class Stack{
    private:
        int top;
    
    public:
        T data[MAX];

        bool push(T i);
        T pop();
        bool isEmpty();
        T peek();

        Stack(){
            top = -1;
        }

        ~Stack(){
            cout<<"Destruct"<<endl;
        }
};

template<class T>
bool Stack<T> :: push(T i){
    if(top >= MAX){
        cout<<"Stack Overflow"<<endl;
        return false;
    }

    data[++top] = i;

    return true;
}

template<class T>
bool Stack<T> :: isEmpty(){
    if(top == -1)
        return true;
    
    return false;
}

template<class T>
T Stack<T> :: pop(){
    if(top == -1){
        cout<<"Stack Underflow"<<endl;
        return 0;
    }

    return data[top--];
}

template<class T>
T Stack<T> :: peek(){
    if(isEmpty()){
        cout<<"EMPTY " <<endl;
        return -1;
    }

    return data[top];
}

int main(){
    Stack<char> s;

    s.push('A');
    s.push('B');
    s.push('C');
    s.push('Z');
    s.push('#');
    s.push('%');

    cout << "PEEK : " << s.peek() << endl;

    s.pop();
    cout << "PEEK : " << s.peek() << endl;

    s.pop();
    cout << "PEEK : " << s.peek() << endl;

    s.pop();
    cout << "PEEK : " << s.peek() << endl;

    cout << "PEEK : " << s.peek() << endl;

    return 0;
}