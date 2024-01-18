#include <iostream>
using namespace std;

// quicksort 
int partition(int arr[5],int start,int end){
    int index=end;
    int count=0;
    for(int i=0;i<end+1;i++){
        if(arr[i]<arr[index]){
            count++;
        }}
        swap(arr[index],arr[count]);
        int i=0, j=end;
        while (i<count && j>count && i<j){
            while(arr[i]<arr[count]){
                i++;
            }
            while(arr[j]>arr[count]){
                j--;
            }
            swap(arr[i],arr[j]);
        } 
      return count;
        
}
   
void quicksort(int arr[5],int start,int end){
    int pivot=partition(arr,start,end);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);
    return;
}
int main(){
    int arr[5]={1,3,5,2,7};
    quicksort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}