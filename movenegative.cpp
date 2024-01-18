#include <iostream>
using namespace std;
void movenegative(int arr[],int n){
    int left=0;
    int right=n-1;
    for(int i=0;i<n;i++){
        if(left<right){
        if(arr[left]<0 && arr[right]<0){
            right--;
        }
        else if(arr[left]<0 && arr[right]>=0){
            swap(arr[left],arr[right]);
            left++; right--;
        }
        else{
            left++;
        }}
    }
}
int main(){
  int arr[5]={-1,2,3,-4,5};
  movenegative(arr,5);
  for(int i=0;i<5;i++)
     cout<<arr[i]<<" ";
    return 0;
}