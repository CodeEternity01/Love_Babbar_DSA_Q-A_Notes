
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
void insertattail(Node* &tail,Node* temp){
    tail->next=temp;
    tail=temp;
}
 
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
// this is one way to solve the linked lis
void sort(Node* &head){
    int zerocnt=0;
    int onecnt=0;
    int twocnt=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zerocnt++;
        }
        else if(temp->data==1){
            onecnt++;
        }
        else{
            twocnt++;
        }
        temp=temp->next;
    }
    head=NULL;
    while(twocnt!=0){
        insertathead(head,2);
        twocnt--;
    }
    while(onecnt!=0){
        insertathead(head,1);
        onecnt--;
    }
    while(zerocnt!=0){
        insertathead(head,0);
        zerocnt--;
    }
}
void sortt(Node* &head){
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;
    Node* onehead=new Node(-1);
    Node* onetail=onehead;
    Node* twohead=new Node(-1);
    Node* twotail=twohead;
    Node* temp=head;
    // create dumby linked list zeo,one,tw0
    while(temp!=NULL){
        if(temp->data==0){
          insertattail(zerotail,temp);
        }
        else if(temp->data==1){
          insertattail(onetail,temp);
        }
        else if(temp->data==2){
          insertattail(twotail,temp);
        }
        temp=temp->next;
    }
    // merge all the dumby lists
    if(onehead->next!=NULL){
      zerotail->next=onehead->next;
      cout<<head->data<<"problem"<<endl;
      }
    else{
        zerotail->next=twohead->next;
        cout<<head->data<<"problem"<<endl;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;
    
    // headsetup
    head=zerohead->next;
    zerohead=NULL;
    onehead=NULL;
    twohead=NULL;
    delete zerohead;
    delete onehead;
    delete twohead;
}
int main(){
    Node* head=NULL;
    insertathead(head,0);
    insertathead(head,1);
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,0);
    insertathead(head,2);
    insertathead(head,1);
    print(head);
    sortt(head);
    print(head);
    return 0;
}