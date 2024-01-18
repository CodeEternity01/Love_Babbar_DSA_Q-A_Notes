// stack are LIFO type of data structure mean in stack "LAST IN FIRST OUT"
// stack can be implemented by two types 1.Array implementation 2.linked list implementation
#include <iostream>
#include <stack>
using namespace std;
// Implementaion of stack using array
class Stack{

    // properties mean data member
    int top;
    int *arr;
    int size;
    

    public:
    // Behaviour means functions
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
   void push(int element){
      if(size-top>1){
        top++;
        arr[top]=element;
      }
      else{
        cout<<"Stack Overflow "<<endl;
      }
   }
   void pop(){
    if(top>=0){
        top--;
    }
    else
     cout<<"Stack Underflow "<<endl;
   }
   int peek(){
    if(top>=0 && top<size)
      return arr[top];
    else{
        cout<<"Stack is Empty "<<endl;
        return -1;
    }
   }
   bool empty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
   }
};
int main(){
    /*
    // creation of stack
    stack<int> s;
    // push operation
    s.push(5);
    s.push(10);
    // pop operation
    s.pop();
    cout<<"printing top element "<<s.top()<<endl;
    // check empty
    
    if(s.empty()){
        cout<<"s is empty "<<endl;
    }
    else{
        cout<<"s is not empty "<<endl;
    }
    // size operation
    cout<<"size of s is "<<s.size()<<endl;
    */
   Stack st(5);
   st.push(22);
   st.push(43);
   st.push(44);
   st.push(22);
   st.push(43);
   st.push(44);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
   
    cout<<st.peek()<<endl;
    cout<<st.empty()<<endl;
    return 0;
}