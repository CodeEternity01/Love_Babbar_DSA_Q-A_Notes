#include <iostream>
#include <stack>
using namespace std;
    /*
   // Q1:: delete middle element of stack
    void solve(stack<int> &inputStack,int count,int N){
        // Base case
        if(count==N/2){
            inputStack.pop();
            return;
        }
        int num=inputStack.top();
        inputStack.pop();
        // Recursive call
        solve(inputStack.count+1,N);
        inputStack.push(num);
    }
    void deletemiddle(stack<int> &inputStack,int N){
       int count=0;
       solve(inputStack,count,N);
    }
    

    // Q2:: valid parentheis
    bool isvalidparentheis(string str){
        int n=str.length();
        if(n==2 || n%2!=0){
            return false;
        }
        stack<char> s;
        for(int i=0;i<n;i++){
            int ch=str[i];
            if(ch=='{' || ch=='[' || ch=='('){
                s.push(ch);
            }
            else if((ch==')' && s.top()=='(' && !s.empty()) || (ch=='}' && s.top()=='{' && !s.empty()) || (ch==']' && s.top()=='[' && !s.empty())){
                s.pop();
            }
            else{
                return false;
            }
        }
        return s.empty();
    }

     
    // Q3:-Insert an element at the bottom of stack
    void insertatbottom(stack<int> &s,int element){
        //Base case
        if(s.empty()){
            s.push(element);
            return;
        }
        int num=s.top();
        s.pop();
        // Recursive call
        insertatbottom(s,element);
        s.push(num);
    }

    // Q4: Reverse stack using recursion
    void reverseStack(stack<int> &s){
        if(s.empty()){
            return;
        }
        int num=s.top();
        s.pop();
        reverseStack(s);
        insertatbottom(s,num);
    }

    // Q5 sortstack : loop use is Not allowed
    void insertSorted(stack<int> &s,int element){
        if((!s.empty() && s.top()<element) || s.empty()){
            s.push(element);
            return;}
      int num=s.top();
      s.pop();
    //   Recursive
      insertSorted(s,element);
      s.push(num);  
    }
    void sortStack(stack<int> &s){
        // Base case
        if(s.empty()){
            return;
        }
        int num=s.top();
        s.pop();
        // recursive call
        sortStack(s);
        insertSorted(s,num);
    }
    // Q6 Redundant bracket(Use-less brackets)
    bool Isredundant(string str){
        stack<char> s;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                s.push(ch);
            }
            else{
                // ch ya toh ')' hai or lowercase letter
                if(ch==')'){
                    bool isRedundant=true;
                    while(s.top()!='('){
                        char top=s.top();
                        if(top=='+' || top=='-' || top=='*' || top=='/'){
                            isRedundant=false;
                        }
                        s.pop();
                    }
                if(isRedundant==true)
                  return true;
            s.pop();
                }
            }
        }
    return false;
    }*/
   // Q7: Find the req minimum change to make string balanced
   int FindMinimumCost(string str){
    // case to find if string is odd 
    if(str.length()%2==1){
       return -1;
    }
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='{'){
            s.push(ch);
        }
        else{
            // ch is closed bracket
            if(!s.empty() && s.top()=='{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
    //  Stack contains invalid expression
    int a=0,b=0;
    while(!s.empty()){
        if(s.top()=='{'){
            b++;
        }
        else{
            a++;
        }
        s.pop();
    }
    int ans=(a+1)/2+(b+1)/2;
    return ans;
   }
      


int main(){
  string str="}}}}";
  cout<<FindMinimumCost(str);


}
    