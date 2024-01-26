

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(const pair<int,int> a,const pair<int,int> b){
        
        double ratio1=double(a.first)/double(a.second);
        double ratio2=double(b.first)/double(b.second);
        
        return ratio1>ratio2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({arr[i].value,arr[i].weight});
        }
        
        sort(v.begin(),v.end(),cmp);
        
      double ans=0;
      int i=0;
      while(W>0 && i<n){
          
          if(W>=v[i].second){
              ans+=v[i].first;
              W-=v[i].second;
              i++;
          }
          else{
              ans+=double(double(v[i].first)/double(v[i].second))*W;
              W=0;
              break;
          }
      }
      
      return ans;
    }
        
};
