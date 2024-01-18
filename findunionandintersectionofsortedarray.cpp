#include <iostream>
using namespace std;
int* Union(int arr1[],int arr2[],int n,int m){
    int p=n+m-1;
    static int arr[100];
    int i=0,j=0,k=0;
   while(i<n && j<m){
    if(arr1[i]==arr2[j]){
        arr[k]=arr1[i];
        i++; j++; k++;
    }
    else{
       arr[k]=arr1[i];
       k++;
       arr[k]=arr2[j];
        j++; i++; k++;
   }
   }
   while(i<n){
    arr[k]=arr1[i];
    i++; k++;
   }
   while(j<m){
    arr[k]=arr2[j];
    j++; k++;
   }
   for(int i=0;i<n+m-1;i++){
     if(arr[i]==arr[i+1]){
         arr[i]=-1;
         i++;
     }
     
   }
   static int ans[100];
    i=0,j=0;
    while(j<n+m){
        if(arr[j]>0){
        ans[i]=arr[j];
        i++; j++;
    }
       else
        j++;
      } 
   return ans;
}
int* intersection(int arr1[],int arr2[],int n,int m){
    int p=n+m-1;
    static int arr[100];
    int i=0,j=0,k=0;
   while(i<n && j<m){
    if(arr1[i]==arr2[j]){
        arr[k]=arr1[i];
        k++;
        arr[k]=arr2[j];
        i++; j++; k++;
    }
    else{
       arr[k]=arr1[i];
       k++;
       arr[k]=arr2[j];
        j++; i++; k++;
   }
   }
   while(i<n){
    arr[k]=arr1[i];
    i++; k++;
   }
   while(j<m){
    arr[k]=arr2[j];
    j++; k++;
   }
   static int ans[100];
   j=0;
    for(int i=0;i<n+m-1;i++){
     if(arr[i]==arr[i+1]){
         ans[j]=arr[i];
         i++; j++;
     }
     
   }
   return ans;
}
int main(){
 int *p; int *q;
 int arr1[4]={1,2,3,4};
 int arr2[5]={1,3,5,6,7};
 p=Union(arr1,arr2,4,5);
 q=intersection(arr1,arr2,4,5);
 for(int i=0;i<9;i++){
    cout<<*(p+i)<<" ";
 }
 cout<<endl;
  for(int i=0;i<9;i++){
    cout<<*(q+i)<<" ";
 }
    return 0;
}