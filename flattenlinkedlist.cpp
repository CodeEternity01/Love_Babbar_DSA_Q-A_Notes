// this is question for flatting the multilevel linked list in sorted ordered
// code to merge the sorted array
Node* merge(Node* &left,Node* &right){
    if(right==NULL)
      return left;
    if(left==NULL)
      return right;
 Node* ans=new Node(-1);
 Node* temp=ans;
//  merge two sorted list
 while(left!=NULL && right!=NULL){
    if(left->data<right->data){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    else{
        temp->next=right;
        temp=right;
        right=right->next;
    }
 }
 while(left!=NULL){
     temp->next=left;
     temp=left;
     left=left->next;

 }
  while(right!=NULL){
    temp->next=right;
    temp=right;
    right=right->next;
 }
 ans=ans->next;
 return ans;
}
Node* flatten(Node* &head){
    // base case
    if(head->right==NULL || head->right->next==NULL){
        return head->right;
    }
    Node* down=head;
    down->next=NULL;
    // Recursive call to flatten the right part of the linked list
    Node* right=flatten(head->right);
    // for mergeing the two sorted list one DOWN ans second RIGHT
    Node* ans=merge(down,right);
    return ans;

}