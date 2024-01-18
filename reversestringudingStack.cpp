// Reversing an array with element swapping is better than using the stack for reversing
// Because In this case space complecity goes to N
#include <iostream>
#include <stack>
using namespace std;
int main(){
    string str="babbar";
    stack<char> s;
    for(int i=0;i<str.length();i++){
        int ch=str[i];
        s.push(ch);
    }
    string ans="";
    while(!s.empty()){
      char ch=s.top();
      ans.push_back(ch);
     s.pop();
    }
    cout<<"Ans is "<<ans;
    return 0;
}