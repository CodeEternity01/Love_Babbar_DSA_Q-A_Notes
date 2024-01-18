// Home work  reverse in doubly linked list.
#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
     ~Node(){
        int value=this->data;
        /// memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    cout<<"memory is free for node with data "<<value<<endl;
    }
};
void insertathead(Node* &head,int data){
     Node* temp=new Node(data);
     temp->next=head;
     head=temp;
}
void insertattail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

// For the deletion at any position.
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;}
    cout<<"NULL";
}
// reverse the linked list using recursion

// reverse the list at interval of k
Node* reverseknode(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    // step1: reverse first k nodes
    Node* forward=NULL;
    Node* curr=head;
    Node* prev=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    // step2: Recursion dekhlega aage to
    if(forward!=NULL){
        head->next=reverseknode(forward,k);
    }
    // step3: return head of reversed list
    return prev;
}


Node* reverse(Node* &head,Node* &tail){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
       Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
 return prev;
}
int main(){
    // head pointed to node1
    Node* head=NULL;
    insertathead(head,12);
    insertathead(head,15);
     insertathead(head,5);
     insertathead(head,6);
     insertathead(head,27);
     insertathead(head,13);
     print(head);
     cout<<endl;
    Node* temp=reverseknode(head,2);
     print(temp);
}