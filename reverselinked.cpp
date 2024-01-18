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
void insertatmiddle(Node* &head,Node* &tail,int data,int pos){
    if(pos==1){
        insertathead(head,data);
        return;
    }
    Node* temp1=new Node(data);
    Node* temp;
    temp=head;
    int cnt=1;
    while(cnt!=pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertattail(tail,data);
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
// reverse the linked list using recursion
Node* reverselink(Node* &head){
    // Base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* chotahead=reverselink(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotahead;
}
// reverse the linked list using recursiom
void reverserec(Node* &head,Node* curr,Node* prev){
    // base case
    if(curr==NULL){
       head=prev;
        return;
    } 
    reverserec(head,curr->next,curr);
    curr->next=prev;
}
// reverse the list 
 
int main(){

    Node* node1=new Node(6);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    // head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    insertathead(head,12);
    insertathead(head,15);
     insertattail(tail,5);
    insertatmiddle(head,tail,440,5);
    insertattail(tail,3);
    insertathead(head,1);
    // deleteathead(head);
    print(head);
    cout<<endl;
    // deleteattail(tail);
    deleteatpos(head,5);
    print(head);
    cout<<endl;
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    Node* newhead=reverse(head,tail);
    cout<<endl;
    head=newhead;
    print(head);
    cout<<endl;
    Node* curr=head;
    Node* prev=NULL;
    cout<<"reverse of linked list using recursion: "<<endl;
    reverserec(head,curr,prev);
    print(head);
    cout<<endl; 
    Node* newh=reverselink(head);
    print(newh);
    return 0;
}