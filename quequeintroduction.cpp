#include <iostream>
#include <queue>
using namespace std;
// creation of queue class
// array can be implement using linked list and array
/*class Queue{
    int qfront;
    int rear;
    int size;
    int* arr;
    public:
     Queue(){
        size=10000;
        arr=new int[size];
        qfront=0;
        rear=0;
     }
     bool isEmpty(){
       if(qfront==rear){
        return true;
       }
       else
        return false;
     }
     void enqueue(int data){
        if(rear==size){
            cout<<"queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
     }
     int dequeue(){
         if(qfront==rear){
            return -1;
         }
         else{ int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
         }
     }
     int front(){
        if(qfront==rear){
            return -1;
        }
        else{
            int ans=arr[qfront];
            return ans;
        }
     }
     int Size(){
        return (rear-qfront);
     }
};*/
// for circular queue
/*class Queue{
    int front;
    int rear;
    int size;
    int* arr;
    public:
     Queue(int n){
        size=n;
        arr=new int[size];
        front=-1;
        rear=-1;
     }
     bool isEmpty(){
       if(front==-1){
        return true;
       }
       else
        return false;
     }
     bool enqueue(int data){
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
            // cout<<"queue is full"<<endl;
            return false;
        }
        else if(front==-1){
            // first element to push
          front=rear=0;
        }
        else if(rear==size-1 && front!=0){
            rear=0;  
        }
        else{
            rear++;
        }
        arr[rear]=data;
        return true;
     }
     int dequeue(){
         if(front==-1){
            return -1;
         }
         int ans=arr[front];
         arr[front]=-1;
         if(front==rear){
            // single element
            front=rear=-1;
         }
         else if(front==size-1){
            front=0;
         }
         else{
            front++;
         }
     return ans;
         
     }
     int Front(){
        if(front==-1){
            return -1;
        }
        else{
            int ans=arr[front];
            return ans;
        }
     }
     int Size(){
        return (rear-front);
     }};*/
// doubly queue
class Doublyqueue{
    int front;
    int rear;
    int size;
    int* arr;
    public:
     Doublyqueue(int n){
        size=n;
        arr=new int[size];
        front=-1;
        rear=-1;
     }
     bool isEmpty(){
       if(front==-1){
        return true;
       }
       else
        return false;
     }
     bool push_front(int data){
      // check full
      if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
         return false;
      }
      else if(front==-1){
         front=rear=0;
      }
      else if(front==0 && rear!=size-1){
         front=size-1;
      }
      else{
         front--;
      }
      arr[front]=data;
      return true;
     }
     bool push_back(int data){
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
            // cout<<"queue is full"<<endl;
            return false;
        }
        else if(front==-1){
            // first element to push
          front=rear=0;
        }
        else if(rear==size-1 && front!=0){
            rear=0;  
        }
        else{
            rear++;
        }
        arr[rear]=data;
        return true;
     }
      int popFront(){
         if(front==-1){
            return -1;
         }
         int ans=arr[front];
         arr[front]=-1;
         if(front==rear){
            // single element
            front=rear=-1;
         }
         else if(front==size-1){
            front=0;
         }
         else{
            front++;
         }
     return ans;
         
     }
     int popRear(){
         if(front==-1){
            return -1;
         }
         int ans=arr[rear];
         arr[front]=-1;
         if(front==rear){
            // single element
            front=rear=-1;
         }
         else if(rear==0){
            rear=size-1;
         }
         else{
            rear--;
         }
     return ans;
         
     }
     int Front(){
        if(front==-1){
            return -1;
        }
        else{
            int ans=arr[front];
            return ans;
        }
     }
     int Size(){
        return (rear-front);
     }};

int main(){
//   queue implementation
  Doublyqueue q(3);
  q.push_front(1);
  q.push_back(2);
  
  cout<<q.popFront();
  cout<<q.popRear();

    return 0;
}