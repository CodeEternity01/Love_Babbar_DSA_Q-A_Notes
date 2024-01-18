#include <iostream>
using namespace std;
int Partition(int arr[],int l,int r){
    if(l>=r)
      return 0;
     int pivot=arr[r];
    int index=0;
    for(int i=0;i<r;i++){
        if(arr[i]<=pivot){
            index++;
        }
    }
    swap(arr[r],arr[index]);
    int i=0,j=r;
    while(i<index && r>index){
        while(arr[i]<=arr[index]){
            i++;
        }
        while(arr[j]>arr[index]){
            j--;
        }
     if(i<index && j>index){
        swap(arr[i],arr[j]);
        i++;
        j--;
     }
    }
    return index;
}
int kthSmall(int arr[],int l,int r,int k){
    
    int pivot=Partition(arr,l,r);
   if(pivot==k-1){
    return arr[pivot];
   }
   else if(pivot>k){
    return kthSmall(arr,l,pivot-1,k);
   }
   else{
    return kthSmall(arr,pivot+1,r,k);
   }
   return kthSmall(arr,l,r,k);
}
int  main(){
    int arr[8]={10,3,6,9,2,4,15,23};
    cout<<kthSmall(arr,0,8,4);
    return 0;
}