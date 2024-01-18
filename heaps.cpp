#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
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
class heap{
   public:
   int arr[100];
   int size=0;
   heap(){
    arr[0]=-1;
    size=0;;

   }
   void insert(int val){
       size=size+1;
       int index=size;
       arr[index]=val;
       while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }
        else{
            return;
        }
       }
   }
   void deletee(){
    if(size==0){
        cout<<"Nothing to delete "<<endl;
        return;
    }
    arr[1]=arr[size];
    size--;
    // take root node to its correct position
    int i=1; 
    while(i<size){
        int leftindex=2*i;
        int rightindex=2*i+1;
        if(leftindex<size && arr[i]<arr[leftindex]){
            swap(arr[i],arr[leftindex]);
            i=leftindex;
        }
        else if(rightindex<size && arr[i]<arr[rightindex]){
            swap(arr[i],arr[rightindex]);
            i=rightindex;
        }
        else{
            return;
        }
    }
   }
   void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   }
};
void heapify(vector<int> &arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
// min heap
void heapifyM(vector<int> &arr,int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[smallest]>arr[left]){
        smallest=left;
    }
    if(right<n && arr[smallest]>arr[right]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapifyM(arr,n,smallest);
    }
}
vector<int> buildMaxheap(vector<int> &arr){
    int n=arr.size();
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    return arr;
}
// heap sort Important
 void heapSort(vector<int> &arr,int n){
    int t=n;
    while(t>1){
        // step1: swap first and last element
        swap(arr[t],arr[1]);
        t--;
        // step2: using heapify place first elemnent at its correct position
        heapify(arr,t,1);
    }
 }
//  question on heap 
// 1: kth smallest element
int kthSmallest(int arr[],int l,int r,int k){
    // step 1: create max heap
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    // step 2
    for(int i=k;i<=r;i++){
       if(arr[i]<pq.top()){
        pq.pop();
        pq.push(arr[i]);
       }
    }
//  step3: answer at top of max heap
return pq.top();
}
// 2: Is binary is heap;
bool isCompletebinaryTree(Node* root,int index,int nodeCount){
    if(root==NULL){
        return true;
    }
    if(index>=nodeCount){
        return false;
    }
    else{
       bool left=isCompletebinaryTree(root->left,2*index+1,nodeCount);
       bool right=isCompletebinaryTree(root->right,2*index+2,nodeCount);
        return (left && right);
    }
}
bool isMaxheap(Node* root){
    // leaf node hai
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){
        return (root->data>root->left->data);
    }
    else{
        bool left=isMaxheap(root->left);
        bool right=isMaxheap(root->right);
        return (left && right && (root->data>root->left->data) && (root->data>root->right->data));
    }
}
int countNode(Node* root){
    if(root==NULL){
        return 0;
    }
    int ans=1+countNode(root->left)+countNode(root->right);
    return ans;
}
bool solve(Node* root){
    int index=0;
    int totalcount=countNode(root);
    if(isCompletebinaryTree(root,index,totalcount) && isMaxheap(root)){
        return true;
    }
    else
     return false;
}
// 3:  merge two binary max-heap
vector<int> mergeHeaps(vector<int> &a,vector<int> &b,int n,int m){
   //step1    merge both arrays
   vector<int> ans;
   for(auto i:a)
    ans.push_back(i);
   for(auto i:b)
     ans.push_back(i);
   // step2 buildheap using that merged array   
   int size=ans.size();
   for(int i=size/2-1;i>=0;i--){
     heapify(ans,size,i);
   }
   return ans;
}
//4: minimum cost of ropes
long long minCost(long long arr[],long long n){
    // create a min heap
    priority_queue<long long,vector<long long>,greater<long long> > pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    long long cost=0;
    while(pq.size()>1){
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();
        long long sum=a+b;
        cost+=sum;
        pq.push(sum);
    }
   return cost;
}

/*// 5:convert bst to minheap
void inorder(Node* root,vector<int> &in){
    if(root==NULL)
     return;
     inorder(root->left,in);
     in.push_back(root->data);
     inorder(root->right,in);
}
void inordertoMinheap(Node* root,vector<int> in,int index){
   root->data=inorder[index++];
   inordertoMinheap(root->left,in,index);
   inordertoMinheap(root->right,in,index);
}
void ConvertBSTtoheap(Node* root){
  vector<int> in;
  inorder(root,in);
  int index=0;
  inordertoMinheap(root,in,index);
}*/
// question of lecture 2
// 6:kth largest sum of subarray
int getkthLargest(vector<int> &arr,int k){
    vector<int> sumStore;
    int n=arr.size();
    // step1:
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;i<n;j++){
            sum+=arr[j];
            sumStore.push_back(sum);
        }
    }
// step 2 sort the sumstore
 sort(sumStore.begin(),sumStore.end());
//  for kth largest
return sumStore[n-k];
}

// approch 6.2  using minheap
int getkthlargest(vector<int> &arr,int k){
    priority_queue<int,vectot<int>,greater<int>> mini;
      int n=arr.size();
    // step1:
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;i<n;j++){
        sum+=arr[i];
        if(mini.size()<k){
            mini.push(sum);
        }
        else{
            if(sum>mini.top()){
                mini.pop();
                mini.push(sum);
            }
        }
}
}
return mini.top();
}

// 7 merge k sorted array "samj nhi aaya aabhi ke liye"
class node{
    public:
      int data;
      int i;
      int j;
      node(int data,int row,int col){
         this->data=data;
         i=row;
         j=col;
      }
};
class compare{
    public:
    bool operator(node* a,node* b){
        return a->data>b->data;
    }
}
vector<int> mergeSortedArrays(vector<vector<int>> &kArray,int k){
    priority_queue<node*,vector<node*>,compare> minHeap;
//   step1: sare arrays k first element insert 
for(int i=0;i<k;i++){
    node* temp=new node(arr[i][0],i,0);
    minHeap.push(temp);
}
vector<int> ans;
// step2
while(minheap.size()>0){
    node* temp2=minHeap.top();
   ans.push_back(temp2->data);
   minHeap.pop();
   int i=temp2->i;
   int j=temp2->j;
   if(j+1<kArray[i].size()){
    node* next=new node(arr[i][j+1],i,j+1);
    minheap.push(next);
   }
}
return ans;
}
//8 merge k sorted linked list
 Node* mergeList(vector<Node*> &listArray){
    priority_queue<Node*>,vector<Node*>,compare> minheap;
    int k=listArray.size();
    if(k==0)
      return NULL;
    // step1:
    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            minheap.push(listArray[i]);
        }
    }
    Node* head=NULL;
    Node* tail=NULL;
    while(minheap.size()>0){
        Node* temp=minheap.top();
        minheap.pop();
        if(head==NULL){
            head=temp;
            tail=temp;
            if(head->next!=NULL){
                minheap.push(head->next);
            }
        }
        else{
            tail->next=temp;
            tail=temp;
            if(tail->next!=NULL){
                minheap.push(tail->next);
            }
        }
    }
    return head;
 }
//  heap hard type of question
// 9: smallest range in k-list
// repeat karna hai
int kSorted(vector<vector<int>> &a,int k,int n){
    int mini=INT16_MAX,maxi=INT16_MIN;
    priority_queue<node*,vector<node*>,compare> minheap;
    for(int i=0;i<k;i++){
        int element=a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        minheap.push(new node(element,i,0));
    }
  int start=mini,end=maxi;
  while(!minheap.empty()){
      node* temp=minheap.top();
      minheap.pop();
      mini=temp->data;
      if(maxi-mini<end-start){
        start=mini;
        end=maxi;
      }
      if(temp->col+1<0){
        maxi=max(maxi,a[temp->row][temp->col+1]);
        minheap.push(new node(a[temp->row][temp->col+1]),temp->row,temp->col+1);
      }
      else{
        break;
      }
  }
  return (end-start+1);
}

//10: midian in a stream
// aproch 1 using insertion sort se sort kar lenge aur mid nikal lenge iski complexcity hogi o(n**2)
// approch2 using minheap maxheap o(nlongn)
int signum(int a,int b){
    if(a==b)
        return 0;
    else if(a>b)
        return 1;
    else
     return -1;
}
void callmedian(int element,priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int>> &mini,int &median){
  switch(signum(maxi.size(),mini.size())){
    case 0: if(element>median){
                mini.push(element);
                median=mini.top()
              }
            else{
                maxi.push(element);
                median=maxi.top();
            }
            break;
    case 1: if(element>median){
                mini,push(element);
                median=(mini.top()+maxi.top())/2;
                 }
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                 median=(mini.top()+maxi.top())/2;
            }
            break;
    case -1: if(element>median){
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median=(mini.top()+maxi.top())/2;
                }
            else{
                maxi.push(element);
                median=(mini.top()+maxi.top())/2;
            }
            break;

  }
}
vector<int> findMedian(vector<int> &arr,int n){
    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    int median=-1;
    for(int i=0;i<n;i++){
        callmedian(arr[i],maxheap,minheap,median);
        ans.push_back(median);
    }
    return ans;
}
int main(){
 vector<int> arr;
  
//   cout<<minCost(arr,4)<<endl;
  cout<<getkthLargest(arr,2);

  
  return 0;
}