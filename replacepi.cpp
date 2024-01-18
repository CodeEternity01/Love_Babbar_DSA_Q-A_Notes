#include <iostream>
using namespace std;
void replacepi(char input[]){
    if(input[0]=='\0'){
        return;
    }
    if(input[0]=='p' && input[1]=='i'){
        cout<<3.14;
        replacepi(input+2);
    }
    else{
         cout<<input[0];
        replacepi(input+1);
    }
}
int main(){
    char input[7]={'p','i','a','b','p','i','c'};
    replacepi(input);
    return 0;
}