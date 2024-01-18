#include <iostream>
#include <vector>
using namespace std;
class solution{
    private:
      void solve( string str,string output,int index,vector<string> &ans){
        //base case
         if(index>=str.size()){
            if(output.length()>0)
            ans.push_back(output);
            return;
         }
        // exclude
         solve(str,output,index+1,ans);
        //include
        char element=str[index];
        output.push_back(element);
        solve(str,output,index+1,ans);
      }
 public:
   vector<string> subsets(string str){
     vector<string> ans;
     string output="";
     int index=0;
     solve(str,output,index,ans);
     return ans;
   }
};
int main()
{   solution obj;
    string str;
   obj.subsets(str);
    return 0;
}