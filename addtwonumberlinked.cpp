#include <iostream>
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
c
void print(Node* &head){
    Node* temp=head;
while(temp!=NULL){
 cout<<temp->data<<"->";
  temp=temp->next;}
  cout<<"NULL"<<endl;
}

 
Node* add(Node* first,Node* second){
    Node* anshead=NULL;
    int carry=0;
    while(first!=NULL || second!=NULL || carry!=0){
        int val1=0;
        if(first!=NULL){
            val1=first->data;
        }
        int val2=0;
        if(second!=NULL){
            val2=second->data;
        }
        int sum=carry+val1+val2;
        int digit=sum%10;
        // add in ans linked list
        insertathead(anshead,digit);
        carry=sum/10;
        if(first!=NULL)
         first=first->next;
        if(second!=NULL)
         second=second->next;
    }

 return anshead;
}
Node* addtwolist(Node* first,Node* second){
    // step1:-reverse input lists
    first=reverse(first);
    second=reverse(second);
    // step2:-add two lists
    Node* ans=add(first,second);
    // step3:-there is No need to reverse our ans because in add function we insert from head in ans:
    return ans;
}
int main(){
    Node* first=NULL;
    Node* second=NULL;
    insertathead(first,5);
    insertathead(first,4);
    insertathead(second,5);
    insertathead(second,4);
    insertathead(second,3);
    // print(first);
    // print(second);
    // Node* ans=addtwolist(first,second);
    //  print(ans);
    return 0;
}