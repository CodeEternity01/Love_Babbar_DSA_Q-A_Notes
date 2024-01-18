#include <iostream>
#include<math.h>
using namespace std;
int kthSmall(int arr[],int l,int r,int k){
    int mini=INT16_MAX;
    for(int i=0;i<k;i++){
         mini=INT16_MAX;
        for(int j=0;j<r;j++){
            if(arr[j]<mini){
                mini=arr[j];
            }
        }
    for(int k=0;k<r;k++){
        if(arr[k]==mini){
            arr[k]=INT16_MAX;
        }
       }
    }
    return mini;
}
int main(){
 int arr[7]={2,4,1,0,7,6,5};
    cout<<kthSmall(arr,0,6,5);
    return 0;
}