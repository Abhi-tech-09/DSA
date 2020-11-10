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

void insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root==NULL){
        root = temp;
        return;
    }

    Node* prev = NULL;
    Node* curr = root;
    while(curr){
        prev = curr;
        if(data > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    if(temp->data > prev->data)
        prev->right = temp;
    else
        prev->left = temp;

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
    for(int i=0;i<9;i++){
        int x;
        cout<<"Enter data: ";
        cin>>x;
        cout<<endl;
        insert(x);
    }

    cout<<"Inorder Traversal: ";
    inOrder(root);
    cout<<endl;

    cout<<"PreOrder traversal: ";
    preOrder(root);
    cout<<endl;

    cout<<"PostOrder traversal: ";
    postOrder(root);
    return 0;
}



