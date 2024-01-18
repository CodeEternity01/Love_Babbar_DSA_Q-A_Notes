#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    if(s>=e)
      return 0;
    int pivot=arr[e];
     int count=0;
     for(int i=0;i<e;i++){
         if(arr[i]<=pivot)
          count++;
     }
     swap(arr[count],arr[e]);
     int i=0,j=e;
     while(i<count && j>count){
         while(arr[i]<=pivot){
          i++;}
         while(arr[j]>pivot){
          j--;}
      if(i<count && j>count){
        swap(arr[i],arr[j]);
          i++; j--;
        }
     }
 return count;
}

void quicksort(int arr[],int s,int e){
    if(s>=e)
     return;
  int pivot = partition(arr,s,e);
   quicksort(arr,s,pivot-1);
   quicksort(arr,pivot+1,e);
}
int main(){
    int arr[9]={3,1,5,4,7,2,6,9,9};
     quicksort(arr,0,8);
     for(int i=0;i<9;i++)
       cout<<arr[i]<<"  "<<endl;
    return 0;
}


