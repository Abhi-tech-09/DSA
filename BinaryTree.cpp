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

void display(Node* temp){
    if(temp==NULL)
        return ;
    display(temp->left);
    cout<<temp->data<<" ";
    display(temp->right);
}

int main(){
    cout<<"Enter root Node:";
    root = createTree();
    display(root);
    return 0;
}
