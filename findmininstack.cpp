#include <iostream>
#include <stack>
using namespace std;
// this is solution by myself with space complexity of o(n) but we need o(1)
int findmin(stack<int> st){
     stack<int> m;
     int mini=INT16_MAX;
    while(!st.empty()){
    int curr=st.top();
    mini=min(curr,mini);
    m.push(mini);
    st.pop();
    }
    return m.top();
    
}

int main(){
  stack<int> st;
  st.push(4);
  st.push(5);
  st.push(8);
  st.push(3);
  st.push(2);
  st.pop();
  cout<<findmin(st);
    return 0;
}