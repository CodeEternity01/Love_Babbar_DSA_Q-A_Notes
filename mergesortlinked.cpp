// this is no data exchange from node can done
// In this method merge sort will be achive though link change
#include <iostream>
#include <vector>
#include <map>
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
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;}
    cout<<"NULL"<<endl;
}
// merge two sorted array
Node* merge(Node* &left,Node* &right){
    if(right==NULL)
      return left;
    if(left==NULL)
      return right;
 Node* ans=new Node(-1);
 Node* temp=ans;
//  merge two sorted list
 while(left!=NULL && right!=NULL){
    if(left->data<right->data){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    else{
        temp->next=right;
        temp=right;
        right=right->next;
    }
 }
 while(left!=NULL){
     temp->next=left;
     temp=left;
     left=left->next;

 }
  while(right!=NULL){
    temp->next=right;
    temp=right;
    right=right->next;
 }
 ans=ans->next;
 return ans;
}
// to find mid
Node* findmid(Node* &head){
   Node* fast=head->next;
   Node* slow=head;
  while(fast!=NULL && fast->next!=NULL){
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}
Node* mergesort(Node* &head){
    // Base case
    if(head==NULL || head->next==NULL){
       return head;
    }
    Node* mid=findmid(head);
    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;
    // recursive calls to sort both half
    left=mergesort(left);
    right=mergesort(right);
    // merge both left and right half
    Node* result=merge(left,right);
    return result; 
}
int main(){
    Node* head=NULL;
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,4);
    insertathead(head,1);
    insertathead(head,5);
    insertathead(head,6);
    insertathead(head,7);
    print(head);
    head=mergesort(head);
    
    print(head);

    return 0;
}