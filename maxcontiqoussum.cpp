#include <iostream>
using namespace std;
int maxsum(int arr[],int n){
    int maxi=INT16_MIN;
    int sum1=0;
    for(int i=0;i<n;i++){
       sum1+=arr[i];
       if(arr[i]<0 && sum1<0){
        sum1=0;
       }
       maxi=max(sum1,maxi);
       
       
    }
    return maxi;
}
int main(){
    int arr[5]={-1,7,-3,4,-5};
     cout<<maxsum(arr,5);
    return 0;
}