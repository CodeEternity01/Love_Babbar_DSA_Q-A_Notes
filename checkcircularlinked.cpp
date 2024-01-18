#include <iostream>
using namespace std;
// circular single linked list
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
        if(this->next==NULL){
            delete next;
            next=NULL;
        }
        cout<<endl<<"memory is free for node with data "<<value<<endl;
    }
};
// For insert a value in linked list after the Node with data element
void insertNode(Node* &tail,int element,int d){
    //  empty list:
    if(tail==NULL){
        Node* Newnode=new Node(d);
        tail=Newnode;
        Newnode->next=Newnode;
        return;
    }
    // list with only one element:
   else{
    // Non-empty list:
    // Assuming that element is present in the list
    Node* curr=tail;
    while(curr->data!=element){
        curr=curr->next;
    }
    // element found->curr is representing element wala node
    Node* Newnode=new Node(d);
    Newnode->next=curr->next;
    curr->next=Newnode;
   }
}
// delete the node with data equal to value

void print(Node* &tail){
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp=tail;
//   do while is very helpfull in this case ...remember..
    do{
        cout<<tail->data<<"->";
        tail=tail->next;
    } while(tail!=temp);
}
// check list is circular or not
bool iscircularlist(Node* tail){
    if(tail==NULL){
        return true;
    }
    Node* temp=tail->next;
    while(temp!=NULL && temp!=tail){
        temp=temp->next;
    }
    if(temp==tail){
        return true;
    }
 return false;
}
int main(){
  Node* node1=new Node(5);
  Node* tail=NULL;
  insertNode(tail,2,2);
  insertNode(tail,2,5);
  insertNode(tail,2,6);
  insertNode(tail,2,5);
  insertNode(tail,5,7);
  insertNode(tail,5,8);
  insertNode(tail,8,9);
//   print(tail);
//    deletevalue(tail,2);
  cout<<endl;
  print(tail);
  cout<<endl;
  if(iscircularlist(tail)){
    cout<<"linkedlist is circular in nature "<<endl;
  }
  else{
    cout<<"linkedlist is not circular"<<endl;
  }
    return 0;
}