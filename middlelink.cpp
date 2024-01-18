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
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;}
    cout<<"NULL";
}
int length(Node* head){
    Node* temp=head;
    if(head==NULL){
        return 0;
    }
    int cnt=1;
    while(temp->next!=NULL){
        cnt++;
        temp=temp->next;
    }
  return cnt;
}
// find middle using two pointer aproch slow && fast.
Node* findmid(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }
   Node* fast=head->next;
   Node* slow=head;
  while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
        fast=fast->next;
    }
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}
// middle element using total length.
int findmiddle(Node* &head){
    int len=length(head);
    int midlen=(len)/2;
    Node* temp=head;
    int cnt=0;
    while(cnt<midlen){
        temp=temp->next;
        midlen++;
    }
    return temp->data;
}

int main(){

    Node* node1=new Node(6);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    Node* head=node1;
    Node* tail=node1;
    insertathead(head,12);
    insertathead(head,15);
    insertathead(head,5);
    insertathead(head,5);
    insertathead(head,3);
    insertathead(head,1);
    print(head);
    cout<<endl;
    cout<<findmiddle(head);
    Node* mid=findmid(head);
    cout<<mid->data;




    return 0;
}