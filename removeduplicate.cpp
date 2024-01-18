#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
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
void insertathead(Node* &head,int d){
     Node* temp=new Node(d);
     temp->next=head;
     head=temp;
}
void insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertatmiddle(Node* &head,Node* &tail,int d,int pos){
    if(pos==1){
        insertathead(head,d);
        return;
    }
    Node* temp1=new Node(d);
    Node* temp;
    temp=head;
    int cnt=1;
    while(cnt!=pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertattail(tail,d);
        return;
    }
    temp1->next=temp->next;
    temp->next=temp1;
}
void deleteathead(Node* &head){
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}
// For the deletion at any position.
void deleteatpos(Node* &head,int pos){
    if(pos==1){
        Node* tempp=head;
        head=head->next;
        tempp->next=NULL;
        delete tempp;
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt!=pos-1){
        temp=temp->next;
        cnt++;
    }
    Node* temp1=temp->next;
    temp->next=temp1->next;
    temp1->next=NULL;
    delete temp1;

}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;}
    cout<<"NULL";
}
// this method helpful only in sorted array:
Node* uniquesortedlist(Node* &head){
    // empty list
    if(head==NULL)
      return NULL;
  Node* curr=head;
  while(curr->next!=NULL){
    if(curr->data==curr->next->data){
       Node* temp=curr->next;
       curr->next=temp->next;
       temp->next=NULL;
       delete temp;
    }
    else{
        curr=curr->next;
    }
  }
  return head;
}
// remove dublicate from unsorted linked list:
// HOME WORK 
/*Node* removeduplicate(Node* &head){
    Node* curr=head;
    while(curr!=NULL){
        Node* temp=curr->next;
        while(temp!=NULL){
            if(curr->data==temp->data){

            }
        }
    }
 }*/
//  split circular linked list into 2 half
//HOME WORK remove dulplicate in unsorted linked list using map
int main(){
    Node* node1=new Node(5);
    Node* head=node1;
    Node* tail=node1;
    insertathead(head,12);
    insertathead(head,15);
    insertattail(tail,5);
    insertatmiddle(head,tail,440,5);
    insertattail(tail,3);
    insertathead(head,1);
    print(head);
    cout<<endl;
    uniquesortedlist(head);
    print(head);
    return 0;
}