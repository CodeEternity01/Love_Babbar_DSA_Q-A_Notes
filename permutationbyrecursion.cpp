#include <iostream>
#include <vector>
using namespace std;
 class solution{
    private:
      void solve(vector<int> num,int index,vector<vector<int>> &ans){
        //Base case
        if(index>=num.size()){
            ans.push_back(num);
            return;
        }
        for(int i=index;i<num.size();i++){
            swap(num[i],num[index]);
            solve(num,index+1,ans);
            // Backtrack
            swap(num[i],num[index]);
        }
      }
    public:
    vector<vector<int>> permutation(vector<int> &num){
     vector<vector<int>> ans;
     string output="";
     int index=0;
     solve(num,index,ans);
     return ans;
   }
 };
int main(){
  solution obj;
  vector<int> num;
  int arr[3]={1,2,3};
  for(int i=0;i<3;i++)
    num.push_back(arr[i]);
    obj.permutation(num);
    return 0;
}