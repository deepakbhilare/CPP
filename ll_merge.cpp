#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = NULL;
        }

        ~LinkedList(){

        }

        Node* getHead(){
            return head;
        }
        void addNode(int val);
        void display(Node *h);
        Node* merge_ll(Node *ll1, Node *ll2);
};

Node* LinkedList :: merge_ll(Node *ll1, Node *ll2){
    if(!ll1) return ll2;
    if(!ll2) return ll1;

    Node* finalHead = NULL;

    if(ll1->data < ll2->data){
        finalHead = ll1;
        ll1 = ll1->next;
    }
    else{
        finalHead = ll2;
        ll2 = ll2->next;
    }

    head = finalHead;

    Node* finalTail = finalHead;

    while(ll1 && ll2){
        if(ll1->data < ll2->data){
            finalTail->next = ll1;
            ll1 = ll1->next;
        }
        else{
            finalTail->next = ll2;
            ll2 = ll2->next;
        }
        finalTail = finalTail->next;
    }

    if(ll1){
        finalTail->next = ll1;
    }
    else{
        finalTail->next = ll2;
    }

    return head;
}

void LinkedList :: addNode(int val){
    Node *n = new Node();

    n->data = val;
    n->next = NULL;

    if(!head)
        head = n;
    else{
        Node *temp = head;

        while(temp->next){
            temp = temp->next;
        } 

        temp->next = n;
    }
}

void LinkedList :: display(Node *h){
    Node *temp = head;

    while(temp){
        cout << "-->" << temp->data ;
        temp = temp->next;
    }

    cout << endl;
}

int main(){
    LinkedList *ll1 = new LinkedList();

    for(int i = 1; i < 10; i = i + 2)
        ll1->addNode(i);
    
    ll1->display(ll1->getHead());

    LinkedList *ll2 = new LinkedList();

    for(int i = 0; i < 10; i = i + 2)
        ll2->addNode(i);
    
    ll2->display(ll2->getHead());

    LinkedList *ll3 = new LinkedList();

    ll3->display(ll3->merge_ll(ll1->getHead(), ll2->getHead()));

   // ll3->display(ll3->getHead());

    return 0;
}