class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;
    public:
    // Initialize Twostack.
    TwoStack(int s){
       this->size=s;
       top1=-1;
       top2=s;
       arr=new int[s];
    }
    // Push in stack 1
    void push1(int element){
        // atleast a empty space
      if(top2-top1>1){
        top1++;
        arr[top]=element;
      }
      else{
        cout<<"stack is overflow"<<endl;
      }
    }
    // push in stack2
    void push2(int element){
       if(top2-top1>1){
        top2--;
        arr[top2]=element;
       }
       else{
        cout<<"Stack is overFlow"<<endl;
       }
    }
    // pop from stack1 and return pop
    int pop1(){
     if(top1>=0){
        int ans=arr[top1];
        top1--;
        return ans;
     }
     else{
        return -1;
     }
    }
    int pop2(){
     if(top2<s){
        int ans=arr[top2];
        top2++;
        return ans;
     }
     else{
        return -1;
     }
    }
    // 

};