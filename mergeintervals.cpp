   #include <iostream>
   #include <vector>
   using namespace std;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;
        for(int i=0;i<intervals.size();i++){
              vector<int> v1;
               int j=0;
                if(intervals[i][j+1]>intervals[i+1][j]){
                    v1.push_back(intervals[i][j]);
                    v1.push_back(intervals[i+1][j+1]);
                    i++;
                }
                else{
                   v1.push_back(intervals[i][j]);
                   v1.push_back(intervals[i][j+1]);
                }
            
             ans.push_back(v1);
        }
        cout<<ans[0][1];
        return ans;
    }
int main(){
    int arr[2][2]={{1,2},{2,4}};
    vector<vector<int>> ans;
    for(int i=0;i<2;i++){
        vector<int> v1;
     for(int j=0;j<2;j++){
        v1.push_back(arr[i][j]);
     }
     ans.push_back(v1);
    }
    merge(ans);
      for(int i=0;i<2;i++){
       for(int j=0;j<2;j++){
        cout<<ans[i][j];
       }}
    return 0;
}