#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
    }
};

Node* head = NULL;

Node* create_ll(Node* prev){
    int data;
    cout<<"Enter element: ";
    cin>>data;

    if(head==NULL){
        prev->data = data;
        prev->next = NULL;
        head = prev;
        return prev;
    }
    else{
        Node* curr = new Node(data);
        curr->next = NULL;
        prev->next = curr;
        return curr;
    }
}

void print_ll(Node* temp){
    temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void sort_ll(){
     Node* i = head;
     Node* j = head;

     while(i){
         j = i->next;
         while(j){
             if(j->data < i->data){
                 int temp = j->data;
                 j->data = i->data;
                 i->data = temp;
             }
             j = j->next;
         }
         i = i->next;
     }
}

void sort_list()
{
    Node *ptr1,*ptr2;
    int temp;
    ptr1 = head;
    while(ptr1 -> next != NULL)
    {
        ptr2 = ptr1 -> next;
        while(ptr2 -> next != NULL)
        {
            if(ptr1 -> data > ptr2 -> data)
            {
                temp = ptr1 -> data;
                ptr1 -> data = ptr2 -> data;
                ptr2 -> data = temp;
            }
            ptr2 = ptr2 -> next;
        }
        ptr1 = ptr1 -> next;
    }
    
};

int main(){
    int n;
    cout<<"Enter the size of LinkedList:";
    cin>>n;
    Node* temp = (Node*)malloc(sizeof(Node));
    for(int i=0;i<n;i++)
        temp = create_ll(temp);
        
    cout<<"Before Sorting:";    
    print_ll(head);
    cout<<endl;
    // sort_ll();
    sort_list();
    cout<<"After Sorting:";
    print_ll(head);
    cout<<endl;

    return 0;
}