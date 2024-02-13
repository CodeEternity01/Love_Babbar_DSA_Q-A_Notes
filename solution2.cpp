#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

     while(t--) {

        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

      unordered_map<int,int> freq;
      for(int i=0;i<n;i++){
        freq[arr[i]]++;
      }
      int fre=0;
      for(auto it: freq){
        if(fre<it.second){
            fre=it.second;
        }
      }
     int ans=n-fre;
      cout<<ans<<endl;

    }

    return 0;
}
