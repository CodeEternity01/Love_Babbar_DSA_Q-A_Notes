#include <iostream>
using namespace std;
int minJump(int arr[],int n){
    int jump=0;
    int currstart=0,currend=0,currmaxreach=-1;
    while(currstart<n-1){
      
        currmaxreach=max(currmaxreach,arr[currstart]+currstart);
        if(currmaxreach>=n-1){
            jump=jump+1;
            break;
        }
      if(currstart==currend){
        jump=jump+1;
        currend=currmaxreach;
      }
      currstart=currstart+1;
    }
 return jump;
}
int main(){
    int arr[5]={2,1,1,1,1};
    cout<<minJump(arr,5);
    return 0;
}