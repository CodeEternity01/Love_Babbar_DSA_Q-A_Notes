  #include <iostream>
  #include <stack> 

  using namespace std;
int maxProfit(int* prices, int size)
{
    // maxProfit adds up the difference between
    // adjacent elements if they are in increasing order
    int maxProfit = 0;
    // The loop starts from 1
    // as its comparing with the previous
   for (int i = 1; i < 6; i++){
    if (prices[i] > prices[i - 1])
     maxProfit+= prices[i] - prices[i - 1];}
    return maxProfit;
}
int main(){
    int arr[6]={7,1,5,3,6,4};
    cout<<maxProfit(arr,5);
}