#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
int maximumFrequency(vector<int> &arr){
    unordered_map<int,int> count;
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }
    int maxi=INT16_MIN;
    int ans=-1;
    for(auto i:count){
        if(i.second>maxi){
            maxi=i.second;
            ans=i.first;
        }
    }
    return ans;
}
int main(){
    int arr[6]={1,2,3,2,1,1};
    vector<int> v;
    for(int i=0;i<6;i++){
        v.push_back(arr[i]);
    }
    cout<<maximumFrequency(v);
    return 0;
}