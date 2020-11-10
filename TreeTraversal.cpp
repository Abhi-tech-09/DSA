#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(){}
    Node(int data){
        this->data = data;
    }
};

Node* root = NULL;

Node*  createTree(){
    Node* temp = new Node();
    int data;
    cin>>data;
    temp->data=data;
    
    if(data==-1)
        return NULL;
    if(root==NULL)
        root = temp;
    
    cout<<"Enter data for left Node of "<<temp->data<<" :"<<endl;
    temp->left = createTree();

    cout<<"Enter data for right Node of "<<temp->data<<" :"<<endl;
    temp->right = createTree();
}

void inOrder(Node* temp){
    if(temp==NULL)
        return;
    
    inOrder(temp->left);
    cout<<temp->data<<" ";
    inOrder(temp->right);
}

void preOrder(Node* temp){
    if(temp==NULL)
        return;

    cout<<temp->data<<" ";
    preOrder(temp->left);
    preOrder(temp->right);
}

void postOrder(Node* temp){
    if(temp==NULL)
        return;

    postOrder(temp->left);
    postOrder(temp->right);
    cout<<temp->data<<" ";
}

int main(){
    cout<<"Enter root Node: ";
    root = createTree();

    cout<<"InOrder traversal: ";
    inOrder(root);
    cout<<endl;

    cout<<"PreOrder traversal: ";
    preOrder(root);
    cout<<endl;

    cout<<"PostOrder traversal: ";
    postOrder(root);
    return 0;
}