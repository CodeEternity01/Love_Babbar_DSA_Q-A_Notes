#include <bits/stdc++.h>
using namespace std;
struct Node{
     int data;
     Node* next;
     Node* random;
    Node(int d){
       data=d;
       next=NULL;
       random=NULL;
    }
};
class solution{
    private:
    void insertattail(Node* &head,Node* &tail,int d){
        Node* newNode=new Node(d);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
           tail->next=newNode;
           tail=newNode;
        }
    }
    public:
    // this is the done with the help of shiftting the next pointer. there is no use of pointer
     Node* copylist2(Node* head){
        // step1: Create a clone list
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        
        Node* temp=head;
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->data);
            temp=temp->next;
        }
        //step2: cloneNodes add between the original list node
        Node* originalNode=head;
        Node* cloneNode=clonehead;
        while(originalNode!=NULL && cloneNode!=NULL){
            Node* next=originalNode->next;
            originalNode->next=clonehead;
            originalNode=next;
            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next;
        }
        //step3: Random pointer copy
         temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random=temp->random? temp->random->next : temp->random;
            }
            temp=temp->next->next;
        }
        //step4: revert chamges that is done in step 2
        originalNode=head;
        cloneNode=clonehead;
         while(originalNode!=NULL && cloneNode!=NULL){
           originalNode->next=cloneNode->next;
           originalNode=originalNode->next;
           if(originalNode!=NULL)
              cloneNode->next=originalNode->next;
           cloneNode=cloneNode->next;
        }
        //step5: return ans
        return clonehead;
        }

    // this is all done with the help of mapping
    Node* copylist(Node* head){
        // step1: Create a clone list
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        
        Node* temp=head;
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->data);
            temp=temp->next;
        }
        // step2: Create a map
        unordered_map<Node*,Node*> oldtonewNode;
        Node* originalNode=head;
        Node* cloneNode=clonehead;
        while(originalNode!=NULL){
             oldtonewNode[originalNode]=cloneNode;
             originalNode=originalNode->next;
             cloneNode=cloneNode->next;
        }
        // step3: set random node
        originalNode=head;
        cloneNode=clonehead;
        while(originalNode!=NULL){
            cloneNode->random=oldtonewNode[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
     return clonehead;
    }
};
int main(){
    

    return 0;
}