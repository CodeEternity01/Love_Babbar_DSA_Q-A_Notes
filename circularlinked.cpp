#include <iostream>
#include <map>
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
void deletevalue(Node* &tail,int value){
    if(tail==NULL){
        cout<<"list is empty,please check again"<<endl;
        return;
    }
   else{
    // Non empty
    // Assuming  that "value" is present in the linked list
    Node* prev=tail;
    Node* curr=prev->next;
    while(curr->data!=value){
        prev=curr;
        curr=curr->next;
    }
    // One node linked list
    if(curr==prev){
        tail=NULL;
    }
    // >=2 Node linked list
    else if(tail==curr){
        tail=prev;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;}
} 

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
bool detectloop(Node* head){
    if(head==NULL){
        return true; 
    }
    map<Node*,bool> visited;

    Node* temp=head;
    while(temp!=NULL){
        // cycle is present
        if(visited[temp]==true){
           return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    // if there is no cycle present then only we can overcome from loop:
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
  print(tail);
   deletevalue(tail,2);
  cout<<endl;
  print(tail);
  cout<<endl;
  cout<<detectloop(tail);
    return 0;
}