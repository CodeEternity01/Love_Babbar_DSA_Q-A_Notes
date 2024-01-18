#include <iostream>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;
// infix=<operand> <operator> <operand> 4*3+2
// prefix=<operator> <operand> <operand> +*423
// postfix <operand> <operand> <operand> 42*3+
// pricediance of operator (),^,* / ,+ -
int prefix(string str){
    stack<char> s;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            s.push(str[i]-'0');
        }
        else{
            int op1=s.top();
            s.pop();
            int op2=s.top();
            s.pop();
        switch(str[i]){
            case '+':
              s.push(op1+op2);
              break;
            case '-':
              s.push(op1-op2);
              break;
            case '*':
              s.push(op1*op2);
              break;
            case '^':
              s.push(pow(op1,op2));
              break;
            case '/':
              s.push(op1/op2);
              break;
        }
        }
    }
    return s.top();
}
int postfix(string str) {
 stack<char> s;
    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
            s.push(str[i]-'0');
        }
        else{
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
        switch(str[i]){
            case '+':
              s.push(op1+op2);
              break;
            case '-':
              s.push(op1-op2);
              break;
            case '*':
              s.push(op1*op2);
              break;
            case '^':
              s.push(pow(op1,op2));
              break;
            case '/':
              s.push(op1/op2);
              break;
        }
        }
    }
    return s.top();}
int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else
     return -1;
}
string infixtopostfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
string infixtoprefix(string s){
    reverse(s.begin(),s.end());

    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
//  string str="-+7*45+20";
//  string str1="46+2/5*7+";
//  cout<<postfix(str1)<<endl;
//  cout<<prefix(str);
 cout<<infixtoprefix("(a-b/c)*(a/k-l)");
 return 0;
}