#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
 Node(int d){
    this->data=d;
    this->prev=NULL;
    this->next=NULL;
 }
 ~Node(){
    int val=this->data;
    if(next!=NULL){
        delete next;
        next=NULL;
    }
    cout<<"memory is free for node with data "<<val<<endl;
 }
};

// For the length of linked list
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
void insertathead(Node* &head,Node* &tail,int d){
    if(head==NULL){
       Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
     Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}
// insertion at tail
void insertattail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;}
}
// Insertion at any pos in linked list
void insertatpos(Node* &head,Node* &tail,int pos,int data){
    if(pos>length(head)+1){
        cout<<endl<<"link cannot be formed position exced limit";
        return;
    }
    Node* temp1=new Node(data);
    Node* temp=head;
    if(pos==1){
        insertathead(head,tail,data);
        return;
    }
    int cnt=1;
    while(cnt!=pos-1){
        cnt++;
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertattail(tail,head,data);
        return;
    }
    temp1->next=temp->next;
    temp->next->prev=temp1;
    temp->next=temp1;
    temp1->prev=temp;
}
// For deleting any node from any position in linked list.
void deleteatpos(Node* &head,Node* tail,int pos){
    if(pos==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt!=pos-1){
        temp=temp->next;
        cnt++;
    }
    Node* curr=temp->next;
    if(curr=tail){
        tail=temp;
        tail->next=NULL;
        curr->prev=NULL;
        delete curr;
        return;
    }
    else{
    curr->prev=NULL;
    temp->next=curr->next;
    curr->next->prev=temp;
    curr->next=NULL;
    delete curr;}

}

// For print the linked list
void print(Node* &head){
    Node* temp=head;
while(temp!=NULL){
 cout<<temp->data<<"->";
  temp=temp->next;}
  cout<<"NULL";
}
int main(){
    Node* node1=new Node(4);
    Node* head=NULL;
    Node* tail=NULL;
    insertathead(head,tail,4);
    insertathead(head,tail,6);
    insertathead(head,tail,2);
    insertathead(head,tail,2);
    insertattail(tail,head,1);
    print(head);
    insertatpos(head,tail,6,30);
    cout<<endl;
    print(head);
    cout<<endl;
    deleteatpos(head,tail,6);
    print(head);
    cout<<endl;
     cout<<head->next->data<<endl;
     cout<<tail->next;
    return 0;
}