#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    private:
        Node *head;
    public:
        LinkedList(){
            head = NULL;
        }

        ~LinkedList(){
            delete this;
        }

        void addNode(int val);
        void reverseList();
        void display();
        void insert_at_given_position(int v, int p);

};

void LinkedList :: insert_at_given_position(int v, int p){
    Node *temp = new Node();

    temp->data = v;

    if(p == 0){
        temp->next = head;
        head = temp;
    }
    else{
        Node *ptr = head;

        while(p > 0){
            ptr = ptr->next;
            --p;
        }

        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void LinkedList :: addNode(int i){
    Node * newNode = new Node();

    newNode->data = i;
    newNode->next = NULL;

    if(!head){
        head = newNode;
    }
    else{
        Node *temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList :: display(){
    Node * temp = head;

    if(head == NULL){
        cout << "EMPTY LL " << endl;
    }
    else{
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
}

int main(){
    LinkedList *list = new LinkedList();

    list->addNode(1);
    list->addNode(2);
    list->addNode(4);
    list->addNode(10);
    list->insert_at_given_position(-1, 0);

    list->display();

    return 0;
}