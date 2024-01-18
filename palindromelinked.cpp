// palindrome mean data is same on left and right ex: 121,nitin...
// lecture 50
#include <iostream>
#include <vector>
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

// For print the linked list
void print(Node* &head){
    Node* temp=head;
while(temp!=NULL){
 cout<<temp->data<<"->";
  temp=temp->next;}
  cout<<"NULL";
}
// ispalindrome
/*bool ispalindrome(Node* &head,Node* &tail){
    Node* left=head;
    Node* right=tail;
    while(left!=right){
        if(left->data==right->data){
            left=left->prev;
            right=right->next;
        }
        else{
            return false;
        }
    }
    return true;
}*/
/*
bool checkpalindrome(vector<int> arr){
    int n=arr.size();
    int s=0;
    int e=n-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
bool ispalindrome(Node* &head){
    vector<int> arr;
    Node* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return checkpalindrome(arr);
}*/
// this is used for sigle linked list
Node* middle(Node* &head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast->next!=NULL && fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node* reverse(Node* head){
   if(head == NULL || head->next == NULL){
      // base case: list is empty or has only one node
      return head;
   }
   Node* new_head = reverse(head->next); // recursively reverse the tail of the list
   head->next->next = head; // set the next node to point to the current node
   head->next = NULL; // set the current node to point to NULL
   return new_head; // return the new head of the reversed list
}
bool palindrome(Node* &head){
    if(head->next==NULL && head==NULL){
        return true;
    }
    // step1=find middle
    Node* mid=middle(head);
    // step2=reverse after mid pointer
    Node* temp=mid->next;
    mid->next=reverse(temp);
    // step3=compare both half
    Node* head1=head;
    Node* head2=mid->next;
    while(head1!=NULL && head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    temp=mid->next;
    mid->next=reverse(temp);
    return true;
}
int main(){
    Node* node1=new Node(4);
    Node* head=NULL;
    Node* tail=NULL;
    insertathead(head,tail,1);
    insertathead(head,tail,2);
    insertathead(head,tail,1);
    cout<<endl;
    cout<<palindrome(head);

    return 0;
}