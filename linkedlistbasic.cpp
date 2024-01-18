// floyd's cycle detetion algorithm home work
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

Node* floyddetectloop(Node* &head){
    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    bool flag=false;
    while(slow!=NULL && fast!=NULL && flag==false){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            if(slow==fast){
                flag=true;
                cout<<"cycle stating "<<slow->data<<endl;
            }
            return slow;
        }
    }}
void removecycle(Node* &head){
    if(head==NULL)
      return;
    Node* temp=floyddetectloop(head);
    Node* temp1=temp->next;
    while(temp1->next!=temp){
        temp1=temp1->next;
    }
    temp1->next=NULL;
}
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
    deleteathead(head);
    //  print(head);
    cout<<endl;
    // deleteattail(tail);
    deleteatpos(head,5);
    //   print(head);
    cout<<endl;
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    cout<<endl;
/*  if(iscircularlist(head)){
    cout<<"linkedlist is circular in nature "<<endl;
  }
  else{
    cout<<8"linkedlist is not circular"<<endl;
  }*/
  cout<<detectloop(head)<<endl;
  tail->next=head->next->next;
  if(floyddetectloop(head)!=NULL){
    cout<<"cycle is present";
  }
  else{
    cout<<"cycle not present";
  }
  cout<<endl;
  removecycle(head);
print(head);
  
    return 0;
}