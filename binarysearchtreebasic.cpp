#include <iostream>
#include <queue>
#include <map>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;
  Node(int d){
    this->data=d;
    this->right=NULL;
    this->left=NULL;
  }
};
// for every node the data in left is smaller than root node and in right the data is always greater than root node
// insert in BST
Node* insertinBST(Node* root,int data){
    // base case
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        // right part me insert karna hai
        root->right=insertinBST(root->right,data);
    }
    else{
        // left part me insert karna hai
        root->left=insertinBST(root->left,data);
    }
    return root;
}
// level order traversal
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            // purana level complete ho chuka hai
            cout<<endl;
            if(!q.empty()){
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
             cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }

}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertinBST(root,data);
        cin>>data;
    }
}
void InOrder(Node* root){
    if(root==NULL){
        return;
    } 
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
// Preorder is NLR
void preOrder(Node* root){
    if(root==NULL){
        return;
    } 
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root){
    if(root==NULL){
        return;
    } 
    
    
    postOrder(root->right);
    cout<<root->data<<" ";
    postOrder(root->left);
}
// 1 search in BST written true if element present else written false
//  approch 1 in recursive way in wrost case time complexcity is o of n and average is logn
bool searchInBST(Node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    if(target>root->data){
        return searchInBST(root->right,target);
    }
    else{
        return searchInBST(root->left,target);
    }
}
// approch 2 iterative way
bool searchinBST(Node *root,int x){
    Node *temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp=temp->left;
        } 
        else{
            temp=temp->right;
        }
    }
    return false;
}
// inOrder of bst is sorted in nature
// 2 min value in BST
Node* minVal(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
// 3 max value in BST
Node* maxVal(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
// h/w InOrder predecesssor and succesor
// deletion of target Nodein Bst
Node* deleteInBst(Node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        // 0 child hai
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 child hai
        // left child hai
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // right child hai
        if(root->right!=NULL && root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }    
        // 2 child hai
        if(root->left!=NULL && root->right!=NULL){
            // do option hai ya toh left me se maximum value nikal lo ya right me se minimum value nikal lo
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteInBst(root->right,mini);
            return root;  
        }
    }
    else if(root->data>val){
        root->left=deleteInBst(root->left,val);
        return root;
    }
    else{
        root->right=deleteInBst(root->right,val);
        return root;
    }
}
// question on binary search tree
// 1 isvalid BST
  // 1.1 approch one is if the inOrder of tree is sorted than the tree is bst 0(n)
  // 1.2 approch two is by the in range the data is lying
  bool isBST(Node* root,int min,int max){
    //    base case
      if(root==NULL){
        return true;
      }
      if(root->data>=min && root->data<=max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left && right;
      }
      else{
        return false;
      }
  }
  bool validBST(Node* root){
     return isBST(root,INT16_MIN,INT16_MAX);
  }

// 2 find kth smallest element in BST
int solve(Node* root,int &i,int k){
    // base case
    if(root==NULL){
        return -1;
    }
    // l
    int left=solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    // n
    i++;
    if(i==k){
        return root->data;
    }
    // r
    return solve(root->right,i,k);
}
// here also for kth largest it will be n-kth term of smallest
int kthsmallest(Node* root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}
// 3 predecessor and successor in BST
pair<int,int> predecessorSuccessor(Node* root,int key){
    // find key
    Node* temp=root;
    int pred=-1; 
    int succ=-1;
    while(root->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
            
        }
        else{
            pred=temp->data;
            temp=temp->right;
            
        }
    }
    // pred and succ
    // pred
    Node* leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    // succ
   Node* rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}
// 3 LCA in BST
// recursive way
Node* LCA(Node* root,Node* p,Node* q){
    // base case
    if(root==NULL){
        return NULL;
    }
    if(root->data<p->data && root->data<q->data){
        return LCA(root->right,p,q);
    }
     if(root->data>p->data && root->data>q->data){
        return LCA(root->left,p,q);
    }
    else{
        return root;
    }
}
// iterative way
Node* LCA2(Node* root,Node* p,Node* q){
    
    while(root!=NULL){
    if(root->data<p->data && root->data<q->data)
        root=root->right;
    else if(root->data>p->data && root->data>q->data)
        root=root->left;
    else
        return root;
    } 
}
// 4 two sum in BST
void inorder(Node* root,vector<int> &in){
    if(root==NULL)
     return;
     inorder(root->left,in);
     in.push_back(root->data);
     inorder(root->right,in);
}
bool twosuminBST(Node* root,int target){
    vector<int> inorderval;
    inorder(root,inorderval);
 int i=0,j=inorderval.size()-1;
 while(i<j){
    int sum=inorderval[i]+inorderval[j];
    if(sum==target)
        return true;

    else if(sum>target){
        j--;
    }
    else{
        i++;
    }
 }
 return false;
}
// 5 flatten the bST in linked list in sorted order
Node* flattenBST(Node* root){
    vector<int> inorderval;
    inorder(root,inorderval);
    int n=inorderval.size();
    Node* newroot=new Node(inorderval[0]);
    Node* curr=newroot;
  for(int i=1;i<n;i++){
    Node* temp=new Node(inorderval[i]);
    curr->left=NULL;
    curr->right=temp;
    curr=temp;
  }
//   3rd step
curr->left=NULL;
curr->right=NULL;
return newroot;
}

// 6 Normal BST to balanced bst
Node* inordertoBST(int s,int e,vector<int> &inorderval){
    // base case
    if(s>e)
      return NULL;
    int mid=(s+e)/2;
    Node* root=new Node(inorderval[mid]);
    root->left=inordertoBST(s,mid-1,inorderval);
    root->right=inordertoBST(mid+1,e,inorderval);
    return root;
}
Node* balancedBST(Node* root){
    vector<int> inorderval;
    // store inorder bst-> sorted values
    inorder(root,inorderval);
    return inordertoBST(0,inorderval.size()-1,inorderval);
} 
// 7 bst form preorder 
    // 7.1 using insertinBST O(n**2) bad solution
    // 7.2 approch sort preorder it convert into inorder,and inordertobst is question 6 o(nlogn)
    // 7.3 using range 
Node* solvee(vector<int> &preorder,int mini,int maxi,int &i){
  if(i>=preorder.size()){
    return NULL;
  }
  if(preorder[i]<mini || preorder[i]>maxi){
    return NULL;
  }
  Node* root=new Node(preorder[i++]);
  root->left=solvee(preorder,mini,root->data,i);
  root->right=solvee(preorder,root->data,maxi,i);
  return root;
}
 Node* preordertoBST(vector<int> &preorder){
    int mini=INT16_MIN;
    int maxi=INT16_MAX;
    int i=0;
    return solvee(preorder,mini,maxi,i);
 }
// 8 merge two BST
// 8.1 approch 0(m+n) ,s(m+n)
vector<int> mergeArray(vector<int> a,vector<int> b){
 vector<int> ans(a.size()+b.size());
 int i=0,j=0,k=0;
 while(i<a.size() && j<b.size()){
    if(a[i]<b[j]){
        ans[k++]=a[i];
        i++;
    }
    else{
        ans[k++]=b[j];
        j++;
    }
 }
 while(i<a.size()){
    ans[k++]=a[i];
    i++;
 }
 while(j<b.size()){
    ans[k++]=b[j];
    j++;
 }
 return ans;
}
Node* mergeBST(Node* root1,Node* root2){
    // step 1: store inorder
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
   vector<int> ans=mergeArray(bst1,bst2);
   int s=0,e=ans.size()-1;
   return inordertoBST(s,e,ans);
}
//8.2 approch  o(m+n),s(height+height)
    // step1: convert a bst into sorted doubly linked list
 void convertIntosortedlinkedlist(Node* root,Node* &head){
    // base case
    if(root==NULL)
       return NULL;
    convertIntosortedlinkedlist(root->right,head);
    root->right=head;
    if(head!=NULL)
      head->left=root;
    head=root;
    convertIntosortedlinkedlist(root->left,head);
 }
Node* mergeLinkedlist(Node* head1,Node* head2){
    Node* head=NULL;
    Node* tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
          if(head==NULL){
            head=head1;
            tail=head1;
            head1=head1->right;
          }
          else{
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
          }
        }
        else{
          if(head==NULL){
            head=head2;
            tail=head2;
            head1=head2->right;
          }
          else{
          tail->right=head2;
            head2->left=tail;
            tail=head2;
            head2=head2->right;
          }
        }
    }
    while(head1!=NULL){
         tail->right=head1;
         head1->left=tail;
         tail=head1;
         head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
       head2->left=tail;
       tail=head2;
      head2=head2->right;
    }
    return head;
}
// convert linked list into bst
int countNode(Node* root){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
Node* sortedlinkedlistToBST(Node* head,int n){
//  base case
 if(n<=0 || head==NULL){
     return NULL;
 }
//  step 1
 Node* left=sortedlinkedlistToBST(head,n/2);
 Node* root=head;
 root->left=left;
 head=head->right;
 root->right=sortedlinkedlistToBST(head,n-n/2-1);
 return root;
}

Node* mergeBST2(Node* root1,Node* root2){
 Node* head1=NULL;
 convertIntosortedlinkedlist(root1,head1);
 head1->left=NULL;
 Node* head2=NULL;
 convertIntosortedlinkedlist(root2,head2);
 head2->left=NULL;
//  step 2
Node* head=mergeLinkedlist(head1,head2);
// step 3
return sortedlinkedlistToBST(head,count(head));

}

//9 Largest BST in binary tree
class Info{
  public:
   int maxi;
   int mini;
   bool isbst;
   int size;
};

Info solve(Node* root,int &ans){
    // base case
    if(root==NULL){
        return {INT16_MIN,INT16_MAX,true,0};
    }
    Info left=solve(root->left,ans);
    Info right=solve(root->right,ans);
    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currnode.mini=min(root->data,left.mini);
    if(left.isbst && right.isbst && (root->data>left.maxi && root->data<right.mini) ){
        currNode.isbst=true;
    }
    else
     currNode.isbst=false;
     if(currNode.isbst){
        ans=max(ans,currNode.size);
     }
     return currNode;
}

int largestBST(Node* root){

    int maxSize=0;
    Info temp=solve(root,maxSize);
    return maxSize;
}
int main(){
    Node* root=NULL;
    cout<<"Enter data to create bst"<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    cout<<twosuminBST(root,20);
 
    return 0;
}