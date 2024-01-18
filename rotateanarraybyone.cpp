#include <iostream>
using namespace std;
int* rotatearray(int arr[],int n){
    static int ans[5];
    ans[0]=arr[n-1];
    for(int i=1;i<n;i++){
        ans[i]=arr[i-1];
    }
    return ans;
}
int main(){
    int *p;
    int arr[5]={1,2,3,4,5};
    p= rotatearray(arr,5);
    for(int i=0;i<5;i++)
       cout<<*(p+i)<<" ";
    return 0;
}