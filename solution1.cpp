#include <iostream>
#include <vector>

using namespace std;

void reverse(string &str){
    int i=0;
    int j=str.length()-1;
    while(i<=j){
        swap(str[i],str[j]);
        i++; j--;
    }


}
string solve(string &str) {
   
   if(str=="")
    return "";

 reverse(str);

 for(int i=0;i<str.length();i++){
    if(str[i]=='A')
      str[i]='T';
    else if(str[i]=='C')
      str[i]='G';
    else if(str[i]=='T')
      str[i]='A';
    else if(str[i]=='G')
      str[i]='C';
 }

 return str;
}

int main() {
    
string str="GTCAG";

cout<<solve(str);

    return 0;
}