#include <iostream>
using namespace std;
class solution{
    private:
    bool issafe(int x,int y,vector<vector<int>> visited,vector<vector<int>> &m){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]=0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m,int n,vector<string> &ans,int x,imt y,vector<vector<int>> visited,srting path){
        // base case: Destination reach
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        // 4 choices - d,l,r,u
        // DOWN
        int newx=x+1;
        int newy=y;
        if(issafe(newx,newy,n,visited,m)){
            path.push_back('D');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        // left
        newx=x;
        newy=y-1;
        if(issafe(newx,newy,n,visited,m)){
            path.push_back('L');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        // right
        newx=x;
        newy=y+1;
        if(issafe(newx,newy,n,visited,m)){
            path.push_back('R');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        // UP
        newx=x-1;
        newy=y;
        if(issafe(newx,newy,n,visited,m)){
            path.push_back('D');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        visited[x][y]=0;

    }
    public:
    vector<string> findpath(vector<vector<int>> &m,int n){
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        int srcx=0;
        int scry=0;
     vector<vector<int>> visited=m;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
     }
     sting path="";
     solve(m,n,ans,scrc,scry,visited,path);
     sort(ans.begin(),ans.end());
     return ans;
    }
}
int main(){

    return 0;
}