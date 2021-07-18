#include<iostream>
#include<queue>

using namespace std;

class Node{

    public:
        int data;

        Node *left;
        Node *right;

        Node(){}

        Node(int d){
            data = d;
        }

        Node *insert(Node*, int);
        Node *createNode(int);
        bool search(Node *root, int data);
        Node *display(Node* root);
        int findMin(Node* root);
        int findMax(Node* root);
        int height(Node* root);

        void levelOrder(Node* root);

        void preorder(Node* root);
        void inorder(Node* root);
        void postorder(Node* root);

        bool isBinarySearchtree(Node* root);
};

bool Node::isBinarySearchtree(Node* root){


    return true;
}

void Node::preorder(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void Node::inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void Node::postorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

void Node::levelOrder(Node* root){
    if(root == NULL) cout << "Empty Tree";

    queue <Node *> Q;

    Q.push(root);

    while(!Q.empty()){
        Node *current = Q.front();
        cout << current->data << " ";

        if(current->left != NULL) 
            Q.push(current->left);
        if(current->right != NULL) 
            Q.push(current->right);
        
        Q.pop();
    }
}

int i = 0;

int Node::height(Node* root){
    if(root == NULL)
        return -1;

    return (max(height(root->right), height(root->left))) + 1;
}

int Node::findMax(Node *root){
    if(root == NULL){
        cout << "Empty Tree" << endl;
        return -1;
    }

    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
}

int Node::findMin(Node *root){
    if(root == NULL){
        cout << "Empty Tree" << endl;
        return -1;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

Node* Node::display(Node *root){
    if(root == NULL)
        cout << "EMPTY" << endl;

    return NULL;
}

bool Node::search(Node *root, int data){
    if(root == NULL){
        cout << "Not Found !!!" << endl;
        return false;
    }
    else if(root->data == data){
        cout << "Found !!!" << endl;
        return true;
    }
    else if(data <= root->data ){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

Node* Node::createNode(int data){
    Node* n = new Node(data);

    n->left = NULL;
    n->right = NULL;

    return n;
}

Node* Node::insert(Node *root, int data){

    if(root == NULL){
        root = createNode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }

    return root;
}

int main(){
    Node *root = NULL;

    root = root->insert(root, 10);
    root = root->insert(root, -1);
    root = root->insert(root, 100);
    root = root->insert(root, 50);
    root = root->insert(root, -2);
    root = root->insert(root, 400);
    root = root->insert(root, 150);
    root = root->insert(root, 1);

    root->search(root, 10);
    root->search(root, 150);
    root->search(root, -100);
    root->search(root, -100);
    root->search(root, 150);

 //   root->display(root);

    cout << "Min : " << root->findMin(root) << endl;
    cout << "Max : " << root->findMax(root) << endl;
    cout << "Height : " << root->height(root) << endl;
    cout << "Level order : " ;root->levelOrder(root); cout << endl;
    cout << "Preorder : "; root->preorder(root); cout << endl;
    cout << "Inorder : "; root->inorder(root); cout << endl;
    cout << "Postorder : "; root->postorder(root); cout << endl;

    cout << endl;

    return 0;
}