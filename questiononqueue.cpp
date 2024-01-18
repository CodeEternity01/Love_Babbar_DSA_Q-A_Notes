#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
/*
// reverse of queue
Appoch 1
 void reversequeue(queue<int> &q){
  if(q.empty()){
    return;
  }
  int t=q.front();
  q.pop();
  reversequeue(q);
  q.push(t);
 }
//  appoch 2
void reversequeue(queue<int> &q){
  stack<int> s;
  while(q.empty()){
    s.push(q.front());
    q.pop();
  }
  while(s.empty()){
    q.push(s.top());
    s.pop();
  }
}*/
// 2 print the first negative number in window of size of k
// appoch 1
/*
void slidingwindow(int arr[],queue<int> &q,int n,int k){
  for(int i=0;i<n;i++){
    if(arr[i]<0 ){
      q.push(arr[i]);
    }
    else if(arr[i+1]<0 && arr[i]>=0){
      q.push(arr[i+1]);
    }
    else{
      q.push(0);
    }
  }
}*/
// appoch 2
/*
 vector<long long> printfirstnegative(long long int a[],long long int n,long long int k){
  deque<long long int> dq;
  vector<long long>ans;
  // process first window of k size
  for(int i=0;i<k;i++){
    if(a[i]<0){
      dq.push_back(i);
    }
  }
  // store anser of first k size window
  if(dq.size()>0){
    ans.push_back(a[dq.front()]);
  }
  else{
    ans.push_back(0);
  }
  // process for remaining window
  for(int i=k;i<n;i++){
    // removal
    if(i-dq.front()>=k && !dq.empty()){
       dq.pop_front();
    }
    // addition
    if(a[i]<0){
      dq.push_back(i);
    }
      for(int i=0;i<k;i++){
    if(a[i]<0){
      dq.push_back(i);
    }
  }
  // store anser of first k size window
  if(dq.size()>0){
    ans.push_back(a[dq.front()]);
  }
  else{
    ans.push_back(0);
  }
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  cout<<ans[0];
return ans;
 }*/
/*
// 3 reverse first k element in queue
void reversequeue(queue<int> &q,int k){
   stack<int> s;
  while(s.size()<k){
    s.push(q.front());
    q.pop();
  }
  while(!s.empty()){
    q.push(s.top());
    s.pop();
  }
  for(int i=0;i<q.size()-k;i++){
    int a=q.front();
    q.pop();
    q.push(a);
  }
 }

// 4 first non repeating element in a sting
string firstnonrepeating(string st){
  queue<int> q;
  unordered_map<char,int> count;
  string ans="";
  int n=st.length();
  for(int i=0;i<n;i++){
    char ch=st[i];
    count[ch]++;
    q.push(ch);
    while(!q.empty()){
      if(count[q.front]>1){
        // repeating char
        q.pop();
      }
      else{
        // non repeating
        ans.push_back(q.front());
        break;
      }
    }
    if(q.empty()){
      ans.push_back('#');
    }
  }

  return ans;
}
// 5 circular tour having petrol pump
// appoch1
int circularTour(int petrol[],int distance[],int n){
 
  int station=0;
 while(station<n-1){
  int remain=0;
   int start=station;
   int j=0;
   bool fuel=true;
    while(j<n && fuel==true){
      remain+=petrol[start]-distance[start];
       if(remain<0){
        
        fuel=false;
        remain=0;
        break;
       }
      
       if(start==n && station>=0){
            start=0;
       }
       start++;
       j++;
      }
      if(fuel){
        cout<<"fuel remain in vehical "<<remain<<endl;
        return station;
      }
      station++;
 }
}
// approch 2
int circularTour(int petrol[],int distance[],int n){
  int deficit=0;
  int balance=0;
  int start=0;
  for(int i=0;i<n;i++){
    balance+=petrol[i]-distance[i];
    if(balance<0){
      deficit+=balance;
      start=i+1;
      balance=0;
    }
  }
  if(deficit+balance>=0){
    return start;
  }
  else
   return -1;
}

// 6 interleave the first half of the queue
// can be done using stack also
void interLeave(queue<int> &q){
   int n=q.size();
   queue<int> newqueue;
   while(q.size()>n/2){
     newqueue.push(q.front());
     q.pop();
   }
   while(!newqueue.empty()){
     q.push(newqueue.front());
     newqueue.pop();
     q.push(q.front());
     q.pop();
   }

//  k queue in an array
class kqueue{
  private:
  int n;
  int k;
  int *front;
  int *rear;
  int *arr;
  int freespot;
  int *next;
 public:
   kqueue(int n,int k){
    this->n=n;
    this->k=k;
    front =new int[k];
    rear=new int[k];
    for(int i=0;i<n;i++){
      front[i]=-1;
      rear[i]=-1;
    }
     next=new int[n];
    for(int i=0;i<n;i++){
      next[i]=i+1;
    }
    next[n-1]=-1;
   
    arr=new int[n];
    freespot=0;
   }
  void enqueue(int data,int qn){
    // overflow
    if(freespot==-1){
      cout<<"No empty space is present "<<endl;
      return;
    }
    // find first free index
    int index=freespot;
    // update freespot
    freespot=next[index];
    // check wheter first element
    if(front[qn-1]==-1){
      front[qn-1]=index;
    }
    else{
      // link new element to the previous
      next[rear[qn-1]]=index;
    }

    // update next
    next[index]=-1;
    // update rear
    rear[qn-1]=index;

    // push element
    arr[index]=data;
  } 
  int dequeue(int qn){
    // underflow condition
    if(front[qn-1]==-1){
      cout<<"queue underflow "<<endl;
      return -1;
    }
    // find index to pop
    int index=front[qn-1];
    // front ko aage badhao
    front[qn-1]=next[index];
    // freespot ko manage karo
    next[index]=freespot;
    freespot=index;
    return arr[index]; 
  }
   };
*/
/l
int solve(int* arr,int n,int k){
  deque<int> maxi(k);
  deque<int> mini(k);

//  addition of first k size window
for(int i=0;i<k;i++){
  while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
    maxi.pop_back();
  }
  while(!mini.empty() && arr[mini.back()]>=arr[i]){
    mini.pop_back();
  }
  maxi.push_back(i);
  mini.push_back(i);
} 
 int ans=0;
 for(int i=k;i<n;i++){
  ans+=arr[maxi.front()+arr[mini.front()]];
  // next window 
  while(!maxi.empty() && i-maxi.front()>=k){
    maxi.pop_front();
  }
  while(!mini.empty() && i-mini.front()>=k){
    minii.pop_front();
  }
  // addition
    while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
    maxi.pop_back();
  }
  while(!mini.empty() && arr[mini.back()]>=arr[i]){
    mini.pop_back();
  }
  maxi.push_back(i);
  mini.push_back(i);
 }
  ans+=arr[maxi.front()+arr[mini.front()]];
}


int main(){
int arr[7]={2,-5,-1,7,-3,-1,-2};
cout<<solve(arr,7)<<endl;


    return 0;
}