#include <iostream>
#include <queue>
using namespace std;
// for multiple Node tree
/*
class Node{
    int data;
    list<Node*> child;
  Node(int d){
    this->data=d;
    
  }
};*/
// for binary tree
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
Node* buildTree(Node* root){
 cout<<"Enter the data "<<endl;
 int data;
 cin>>data;
 root=new Node(data);
 if(data==-1){
    return NULL;
 }
 cout<<"Enter data for inserting in left of "<<data<<endl;
 root->left=buildTree(root->left);
 cout<<"Enter data for inserting in right of "<<data<<endl;
 root->right=buildTree(root->right);
 return root;

}
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
// InOrder is LNR
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
// morrish traversal
void morris(Node* root){
    map<Node*,bool> visited;
    if(root==NULL){
        return;
    }
    Node* current=root;
    Node* predecessor
    while(current!=NULL){
        if(!root->left){
            visited[current]=1;
            current=current->right;
        }
    }
    else{
        predecessor=find(current);
        if(predecessor->right==NULL){
            predecessor->right=current;
            current=current->left;
        }
        else{
            predecessor->right=NULL;
            visited[current]=1;
            current=current->right;
        }
    }

}
int main(){
 Node* root=NULL;
//  creating a tree
 root=buildTree(root);
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// level Order traversal
cout<<"Printing the level order Traversal "<<endl;
levelOrderTraversal(root);
cout<<"InOrder traversal"<<endl;
InOrder(root);
cout<<endl;
cout<<"preOrder traversal"<<endl;
preOrder(root);
cout<<endl;
cout<<"postOrder traversal"<<endl;
postOrder(root);

 return 0;
}
