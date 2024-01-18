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
// question on binary search tree
// 1 isvalid BST
  // 1.1 approch one is if the inOrder of tree is sorted than the tree is bst 0(n)
  // 1.2 approch two is by the in range the data is lying
  bool isBST(Node* root,int min,int max){
    //    base case
      if(root==NULL){
        return true;
      }
      if(root->data>min && root->data<max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left && right
      }
      else{
        return false;
      }
  }
  bool validBST(Node* root){
     return isBST(root,INT16_MIN,INT16_MAX);
  }

int main(){

return 0;
}