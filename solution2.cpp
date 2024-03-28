#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int t;

    cin >> t;

     while(t--) {

       string str;
       cin>>str;

       string hour=str.substr(0,2);
       string min=str.substr(3,2);

       int a=stoi(hour);

       if(a<=11 && a!=0){
        cout<<str<<" "<<"AM"<<endl;
       }
       else if(a==12){
        cout<<str<<" "<<"PM"<<endl;
       }
       else if(a==0  ){
        cout<<"12"<<":"<<min<<" "<<"AM"<<endl;
       }
       else{
        a=a-12;
         hour=to_string(a);
        if(a<=9){
           cout<<"0"<<hour<<":"<<min<<" "<<"PM"<<endl;
        }
       else
        cout<<hour<<":"<<min<<" "<<"PM"<<endl;
       }


    }

    return 0;
}
