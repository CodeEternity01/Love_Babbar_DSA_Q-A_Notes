/*Hashmap has best time complexity for insertion ,deletion and searching
In map value are stored in form of key and values   
*/
// implementation of hashmap by linked list se nahi ho sakta 
// implementation of unorderedmap done using hashtable in time complexity of o(1)
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// max occuring character in a string 
char maxfreqchar(string str){
    int arr[26]={0};
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        arr[ch-'a']++;
    }
    int max=-1;
    int index=0;
    for(int i=0;i<26;i++){
        if(arr[i]>max){
            max=arr[i];
            index=i;
        }
    }
    char ans='a'+index;
    return ans;
}
int maximumFrequency(vector<int> &arr,int n){
    unordered_map<int,int> count;
    int maxFreq=0;
    int maxAns=0;
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
        maxFreq=max(maxFreq,count[arr[i]]);
    }
  for(int i=0;i<arr.size();i++){
    if(maxFreq==count[arr[i]]){
        maxAns=arr[i];
        break;
    }
  }
  return maxAns; 
}
// find most repeated word in a sentance
// mera name love babbar nahi mera babbar hai


int main(){
    // creation
    unordered_map<string,int> m;
   
    // insertion
    // #1 
    pair<string,int> p=make_pair("babbar",3);
    m.insert(p);
    // 2
    pair<string,int> pair2("love",2);
    m.insert(pair2);
    // 3
    m["mera"]=1;
    // searching
    // below two line have difference in output when search for value of unknown key ,first line give 0,
    // second will give error of key not found
    cout<<m["babbar"]<<endl;
    cout<<m.at("love")<<endl;
    // size
    cout<<m.size()<<endl;
    // To check presence ,if present ans is 1 else 0
    cout<<m.count("babbar") <<endl;
    // Erase
    // m.erase("love");
    cout<<m.size()<<endl;
    // traversal
    for(auto i:m){
        cout<<i.first<<"  "<<i.second<<endl;
    }
    // using iterator
     unordered_map<string,int> :: iterator it=m.begin();
     while(it!=m.end()){
     cout<<it->first<<"  "<<it->second<<endl;
     it++;}
    return 0;   
}