#include <iostream>
#include <stack>
using namespace std;
class Nstack{
//    initilisation of data members
int* arr;
int size;
int* top;
int* next;
int freespot;
// s is size of array and n is number of stack
int n,s;
public:
 Nstack(int N,int S){
    n=N;
    s=S;
    arr=new int[s];
    top=new int[n];
    next=new int[s];
    // top initlisation
    for(int i=0;i<n;i++){
        top[i]=-1;
    }
    // next inilisation
    for(int i=0;i<s;i++){
        next[i]=i+1;
    }
    // update last index
    next[s-1]=-1;
    // inilisation free spot
    freespot=0;
 }
//  pushes 'x' int0 the mth stack,return true if it get pushed into the stack and fALSE OTHERWISE
bool push(int x,int m){
    // check for overflow
    if(freespot==-1){
        return false;
    }
    // find index;
    int index=freespot;
    // update freespot
    freespot=next[index];
    // insert element into the array
    arr[index]=x;
    // update next
    next[index]=top[m-1];
    //  update top
    top[m-1]=index;
      
    return true;
}
// pops top element from mth stack, return -1 if the the stack is empty
int pop(int m){
    // check is stack is underflow

    if(top[m-1]==-1){
        return -1;
    }
    int index=top[m-1];

    top[m-1]=next[index];
   
    next[index]=freespot;
    freespot=index;
    return index;
}

};
int main(){
    Nstack s(3,6);
    cout<< s.push(10,1);
    cout<< s.pop(1);
    return 0;
}