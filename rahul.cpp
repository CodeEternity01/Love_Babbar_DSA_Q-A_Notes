 #include <iostream>
 #include <vector>
 using namespace std;
void solve(string digits,string output,int index,vector<string> &ans,string mapping[]){
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }
    int number=digits[index]-'0';
    string value=mapping[number];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,mapping);
        output.pop_back();
    }

}
 vector<string> phone_keypad(string digits){
    vector<string> ans;
    if(digits.length()==0)
       return ans;
    string output;
    int index=0;
    string mapping[10]={"0","1","abc","def","ghi","jkl","mno","pqr","stw","xyz"};
    solve(digits,output,index,ans,mapping);
    
 }

 main(){
    vector<string> v;
    string str="123";
   phone_keypad(str);
    return 0;
 }