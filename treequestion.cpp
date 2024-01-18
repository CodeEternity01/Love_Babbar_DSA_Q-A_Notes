#include <iostream>
#include <map>
#include <queue>

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
// 1 height of binary tree
int height(Node* root){
    if(root==NULL){
        return 0;
    } 
   int h1=height(root->left);
   int h2=height(root->right);
    return max(h1,h2)+1;
}
// 2 diameter of binary tree=longest path for any two node
pair<int,int> diameterfast(Node* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=diameterfast(root->left);
    pair<int,int> right=diameterfast(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int diameter(Node* root){
    return diameterfast(root).first;
}
// 3 check balanced tree
// apporch 1
bool checkbalanced(Node* root){
    if(root==NULL){
        return true;
    }
    bool left=checkbalanced(root->left);
    bool right=checkbalanced(root->right);

    bool diff=abs(height(root->left)-height(root->right))<=1;
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
 } 
//  apporch 2 using pair
pair<bool,int> isbalancedfast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<int,int> left=isbalancedfast(root->left);
    pair<int,int> right=isbalancedfast(root->right);
    bool leftans=left.first;
    bool rightans=right.first;
    bool diff=abs(left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;
    if(leftans && rightans && diff){
        ans.first=true;
    }
    else{
       ans.first=false;
    }
    return ans;
}
bool isbalanced(Node* root){
   return isbalancedfast(root).first;
}
// 4 determine two trees are identical or not
bool isidentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }
   bool left=isidentical(root1->left,root2->left);
    bool right=isidentical(root1->right,root2->right);
    bool value=root1->data==root2->data;
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}
// 5 sum tree for binary tree here for each node sum of left node and right node is equal to that node
pair<bool,int> issumfast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int> leftans=issumfast(root->left);
     pair<bool,int> rightans=issumfast(root->right);
     bool left=leftans.first;
     bool right=rightans.first;
     bool sum=(leftans.second+rightans.second)==root->data;
     pair<bool,int> ans;
     if(left && right && sum){
        ans.first=true;
        ans.second=2*root->data;
     }
     else{
        ans.first=false;
     }
     return ans;
}
int issum(Node* root){
return issumfast(root).second;
}
// 6 zig zag traversal
vector<int> zigzag(Node* root){
    vector<int> result;
    if(root==NULL){
        return result;
    }
    queue<Node*> q;
    q.push(root);
    bool lefttoright=true;
    while(!q.empty()){
        // level process
        int size=q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            Node* frontNode=q.front();
            q.pop();
            int index=lefttoright? i:size-1;
            ans[index]=frontNode->data;
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
        }}
        // change the direction
        lefttoright=!lefttoright;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;

}
// 7 boundary traversal
void traverseleft(Node* root,vector<int> &ans){
  if(root==NULL || (root->left==NULL && root->right==NULL)){
    return;
  }
  ans.push_back(root->data);
  if(root->left){
    traverseleft(root->left,ans);
  }
  else{
    traverseleft(root->right,ans);}
}
void traverseleaf(Node* root,vector<int> &ans){
    // base case
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
}
void traverseright(Node* root,vector<int> &ans){
   if(root==NULL || (root->left==NULL && root->right==NULL)){
    return;
   }
   if(root->right)
    traverseright(root->right,ans);
   else
    traverseright(root->left,ans);
    ans.push_back(root->data);
}
vector<int> boundary(Node* root){
       vector<int> ans;
       if(root==NULL){
        return ans;
       }
       ans.push_back(root->data);
    //    left part print
    traverseleft(root->left,ans);
    // travers leaf node
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
    traverseright(root->right,ans);
    return ans;
    }
// 8 vertical order traversal
    vector<int> verticalOrder(Node* root){
        map<int,map<int,vector<int> > > nodes;
        queue<pair<Node*,pair<int,int> > > q;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*,pair<int,int> > temp=q.front();
            q.pop();
            Node* frontnode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            nodes[hd][lvl].push_back(frontnode->data);
            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            }
           if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i: nodes){
            for(auto j : i.second){
                for(auto k :j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
    // 9 Top view;
    vector<int> topView(Node* root){
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> topnode;
        queue<pair<Node*,int> > q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            Node* frontnode=temp.first;
            q.pop();
            int hd=temp.second;
            // one to one making
            if(topnode.find(hd)==topnode.end()){
                topnode[hd]=frontnode->data;
            }
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:topnode){
            ans.push_back(i.second);
        }
        return ans;
    }
// 10 bottom view
vector<int> bottomView(Node* root){
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> topnode;
        queue<pair<Node*,int> > q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            Node* frontnode=temp.first;
            q.pop();
            int hd=temp.second;
            // one to one making
                topnode[hd]=frontnode->data;
            
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:topnode){
            ans.push_back(i.second);
        }
        return ans;
    }
// 11 leftview of binary tree
// 12 rightview of binary tree 64.last5min
// 13 sum of the longest bloodline of a tree
void solve(Node* root,int sum,int &maxsum,int len,int &maxlen){
   if(root==NULL){
    if(len>maxlen){
        maxlen=len;
        maxsum=sum;
    }
    else if(len==maxlen){
         maxsum=max(sum,maxsum);
    }
    return;
   }
   sum=sum+root->data;
   solve(root->left,sum,maxsum,len+1,maxlen);
   solve(root->right,sum,maxsum,len+1,maxlen);
}
int sumoflongroottoleafpath(Node* root){
    int len=0;
    int maxlen=0;
    int sum=0;
    int maxsum=INT16_MIN;
    solve(root,sum,maxsum,len,maxlen);
    return maxsum;
}
// 14 lowest common ancester in a binary tree
Node* lca(Node* root,int n1,int n2){
    // base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftans=lca(root->left,n1,n2);
    Node* rightans=lca(root->right,n1,n2);
    if(leftans!=NULL && rightans!=NULL){
      return root;
    }
    else if(leftans!=NULL && rightans==NULL){
        return leftans;
    }
    else if(leftans==NULL && rightans!=NULL){
        return rightans;
    }
    else{
        return NULL;
    }
}
// 15k sum paths
void solve(Node* root,int k,int &count,vector<int> path){
   if(root==NULL)
    return;
    path.push_back(root->data);
    // for left
    solve(root->left,k,count,path);
    // for right
    solve(root->right,k,count,path);
    // check for k sum
    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }
 path.pop_back();
}
int sumk(Node* root,int k){
    vector<int> path;
    int count=0;
    solve(root,k,count,path);
    return count;
}


// 16 kth ancestor in a tree
Node* solvee(Node* root,int &k,int node){
    // base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node* leftans=solvee(root->left,k,node);
    Node* rightans=solvee(root->right,k,node);
    if(leftans!=NULL && rightans==NULL){
        k--;
        if(k==0){
            k=INT16_MAX;
            return root;
        }
        return leftans;
    }
    if(rightans!=NULL && leftans==NULL){
        k--;
        if(k==0){
            k=INT16_MAX;
            return root;
        }
        return rightans;
    }
 return NULL;
}
int kthAncestor(Node* root,int k,int node){
   Node* ans=solvee(root,k,node);
   if(ans==NULL || ans->data==node) 
    return -1;
    else
   return ans->data;
}
// maximum sum of non adejecent node 
pair<int,int> solveee(Node* root){
    // base case
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
     pair<int,int> leftans=solveee(root->left);
     pair<int,int> rightans=solveee(root->right);
     pair<int,int> res;
     res.first=root->data+leftans.second+rightans.second;
     res.second=max(leftans.first,leftans.second)+max(rightans.first,rightans.second);
     return res; 
}
int getmaxsum(Node* root){
    pair<int,int> ans=solveee(root);
    return max(ans.first,ans.second);
}
// hard type of question
// 18 construct tree using inorder/preorder traversal
void createmaping(int in[],map<int,int> &nodetoIndex,int n){
    for(int i=0;i<n;i++){
       nodetoIndex[in[i]]=i;
    }
}
Node* solveeee(int in[],int pre[],int &index,int inorderstart,int inorderend,map<int,int> &nodetoIndex,int n){
    // base case
    if(index>=n || inorderstart>inorderend){
        return NULL;
    }
    int element=pre[index++];
    Node* root=new Node(element);
    int position=nodetoIndex[element]; 
    // recursive call
    root->left=solveeee(in,pre,index,inorderstart,position-1,nodetoIndex,n);
    root->right=solveeee(in,pre,index,position+1,inorderend,nodetoIndex,n);
    return root;
}
Node* buildtree(int in[],int pre[],int n){
    int preorderIndex=0;
    map<int,int> nodetoIndex;
    // create node to index map
    createmaping(in,nodetoIndex,n);
    Node* ans=solveeee(in,pre,preorderIndex,0,n-1,nodetoIndex,n);
    return ans;
}
// 19 create a tree from Inoder/postorder
void createmapings(int in[],map<int,int> &nodetoIndex,int n){
    for(int i=0;i<n;i++){
       nodetoIndex[in[i]]=i;
    }
}
Node* solveeeee(int in[],int post[],int &index,int inorderstart,int inorderend,map<int,int> &nodetoIndex,int n){
    // base case
    if(index<0 || inorderstart>inorderend){
        return NULL;
    }
    int element=post[index--];
    Node* root=new Node(element);
    int position=nodetoIndex[element]; 
    // recursive call
    // we first build that part where the next element lying
    root->right=solveeeee(in,post,index,position+1,inorderend,nodetoIndex,n);
    root->left=solveeeee(in,post,index,inorderstart,position-1,nodetoIndex,n);
 
    return root;
}
Node* buildtrees(int in[],int post[],int n){
    int postorderIndex=n-1;
    map<int,int> nodetoIndex;
    // create node to index map
    createmapings(in,nodetoIndex,n);
    Node* ans=solveeeee(in,post,postorderIndex,0,n-1,nodetoIndex,n);
    return ans;
}
// 20 minimum time to burn a tree
// create mapping and written the target node
Node* createparentmapping(Node* root,int target,map<Node*,Node*> &nodetoparent){
   Node* result=NULL;
   queue<Node*> q;
   q.push(root);
   nodetoparent[root]=NULL;
   while(!q.empty()){
     Node* front=q.front();
     q.pop();
     if(front->data==target){
        result=front;
     }
    if(front->left){
        nodetoparent[front->left]=front;
        q.push(front->left);
    }
    if(front->right){
        nodetoparent[front->right]=front;
        q.push(front->right);
    }
   }
   return result;
}
int burntree(Node* root,map<Node*,Node*> &nodetoparent){
    map<Node*,bool> visited;
    queue<Node*> q;
    q.push(root);
    visited[root]=true;
    int ans=0;
    while(!q.empty()){
        bool flag=0;
       int size=q.size();
       for(int i=0;i<size;i++){
        // process neighouring node
        Node* front=q.front();
        q.pop();
        if(front->left && !visited[front->left]){
            flag=1;
            q.push(front->left);
            visited[front->left]=1;
        }
       if(front->right && !visited[front->right]){
        flag=1;
            q.push(front->right);
            visited[front->right]=1;
        }
        if(nodetoparent[front] && !visited[nodetoparent[front]]){
            flag=1;
            q.push(nodetoparent[front]);
            visited[nodetoparent[front]]=1;
        }
       }
       if(flag==1){
        ans++;
       }
    }
    return ans;
}
int mintree(Node* root,int target){
     map<Node*,Node*> nodetoparent;
     Node* targetnode=createparentmapping(root,target,nodetoparent);
    return burntree(targetnode,nodetoparent);
}
// 21 flatten the binary tree using morris traversal
   void flatten(Node* &root){
    Node* current=root;
    while(current!=NULL){
        
        if(current->left){
            Node* pred=current->left;
            while(pred->right!=NULL){
                pred=pred->right;
            }
            pred->right=current->right;
            current->right=current->left;
            current->left=NULL;
        }
        current=current->right;
    }
   
   }
int main(){
 Node* root=new Node(1);
 root->left=new Node(2);
 root->left->left=new Node(3);
   cout<<mintree(root,3);
    return 0;
}