#include <iostream>
#include <vector>
using namespace std;
bool issafe(int newx,int newy,vector<vector<bool>> &visited,vector<vector<int>> &arr,int n){
    if((newx>=0 && newx<n ) && (newy>=0 && newy<n) && (visited[newx][newy]!=1 && arr[newx][newy]==1)){
        return true;
    }
    else{
        return false;
    }
}
void solve(int x,int y,vector<vector<int>> &arr,int n,vector<string> &ans,vector<vector<bool>> &visited,string path){
    // base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
    }
//   4 movement
// D ,L,R,U
// down
if(issafe(x+1,y,visited,arr,n)){
   visited[x][y]=1;
   solve(x+1,y,arr,n,ans,visited,path+'D');
   visited[x][y]=0;
}
// left
if(issafe(x,y-1,visited,arr,n)){
   visited[x][y]=1;
   solve(x,y-1,arr,n,ans,visited,path+'L');
   visited[x][y]=0;
}
// right
if(issafe(x,y+1,visited,arr,n)){
   visited[x][y]=1;
   solve(x,y+1,arr,n,ans,visited,path+'R');
   visited[x][y]=0;
}
// up
if(issafe(x-1,y,visited,arr,n)){
   visited[x][y]=1;
   solve(x-1,y,arr,n,ans,visited,path+'U');
   visited[x][y]=0;
}


}
vector<string> searchMaze(vector<vector<int>> &arr,int n){
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path="";
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,n,ans,visited,path);
    return ans; 
}
int main(){
    
    return 0;
}