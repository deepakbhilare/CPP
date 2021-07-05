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
        Node* delete_from_end(int p);
        Node* deleteNode(int p);

};

Node* LinkedList :: delete_from_end(int p){
    Node* one = head;
    Node* two = head;

    while(p--){
        two = two->next;
    }

    if(!(two->next))
        head = NULL;

    while(two->next){
        one = one->next;
        two = two->next;
    }

    one->next = one->next->next;

    return head;
} 

Node* LinkedList :: deleteNode(int p){
    if(head && p == 0){
        Node *newHead = head->next;

        head->next = NULL;
        delete head;

        head = newHead;

        return head;
    }
    else{
        int i = 0;
        Node *cur = head;

        while(cur && i < p - 1){
            cur = cur->next;
            i++;
        }

        if(cur && cur->next){
            Node * temp = cur->next;

            cur->next = cur->next->next;

            temp->next = NULL;
            delete temp;     
            return head;
        }
    }

    cout << "Empty LL";

    return NULL;
}

void LinkedList :: reverseList(){
    if(head->next == NULL){
        display();
        return;
    }

    Node *curr = head;
    Node *next = head->next;
    Node *prev = NULL;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

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

    cout << endl;
}

int main(){
    LinkedList *list = new LinkedList();

    list->addNode(1);
    list->addNode(2);
    list->addNode(4);
    list->addNode(10);
    list->insert_at_given_position(-1, 0);
    list->insert_at_given_position(-2, 0);
    list->addNode(100);

    list->display();

    list->deleteNode(0);
    list->display();

    list->deleteNode(3);
    list->display();

    list->reverseList();
    list->display();

    list->delete_from_end(2);
    list->display();

    return 0;
}