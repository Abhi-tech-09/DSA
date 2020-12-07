#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right; 
};

Node* root = NULL;

void insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    if(root == NULL) {
        root = temp;
        return;
    }

    Node* curr = root;
    Node* prev = NULL;

    while(curr){
        prev = curr;
        if(data >= curr->data) curr = curr->right;
        else if(data < curr->data) curr = curr->left;
    }

    if(data >= prev->data){
        prev->right = temp;
    }
    if(data < prev->data){
        prev->left = temp;
    }

}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int successor(int key){

    //First I will search for the Node that has data equal to the key given
    Node* temp = root;
    while(temp && temp->data != key){
        if(key > temp->data) temp = temp->right;
        else temp = temp->left;
    }
    if(temp == NULL) return -1;

    //If the Node has right subtree
    if(temp->right != NULL){
    temp = temp->right;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
    }

    //If the Node has no Subtree
    else{
        Node* ancenstor = root;
        Node* succ = NULL;
        while(ancenstor != temp){
            if(temp->data < ancenstor->data){
                succ = ancenstor;
                ancenstor = ancenstor->left;
            }
            //This is because if we move to the right then the 
            //current data must be greater then key hence not updating succ
            else ancenstor = ancenstor->right;
        }
        return succ->data;
    }
}
//                                            Sample Tree
//                                                15 
//                                            /         \ 
//                                           10          20
//                                          /  \        /  \
//                                         8    12     17   25
//                                        /     /      /     \
//                                       6     11     16      26
 

int main(){
    int n;
    cin>>n;
    cout<<"insert nodes !!";
    for(int i=0;i<n;i++){
        cout<<"Enter: ";
        int x;
        cin>>x;
        insert(x);
    }

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl<<"Enter the key for which u want to find the successor"<<endl;
    int node;
    cin>>node;
    cout<<successor(node);    
}
