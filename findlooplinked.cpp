#include <iostream>
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
};
bool detectloop(Node* head){
  
Node* floyddetectloop(Node* &head){
    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
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
                cout<<"cycle stating "<<slow->data;
            }
            return slow;
        }
    }
  return NULL;
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
int main(){
    return 0;
}