#include <iostream>
#include <vector>
using namespace std;
class solution{
    private:
      void solve( vector<int> num,vector<int> output,int index,vector<vector<int>> &ans){
        //base case
         if(index>=num.size()){
            ans.push_back(output);
            return;
         }
        // exclude
         solve(num,output,index+1,ans);
        //include
        int element=num[index];
        output.push_back(element);
        solve(num,output,index+1,ans);
      }
 public:
   vector<vector<int>> subsets(vector<int> &num){
     vector<vector<int>> ans;
     vector<int> output;
     int index=0;
     solve(num,output,index,ans);
     return ans;
   }
};
int main()
{   solution obj;
    vector<int> num;
    int arr[3]={1,2,3};
    for(int i=0;i<3;i++){
       num.push_back(arr[i]);
    }
    obj.subsets(num);

    return 0;
}