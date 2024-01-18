// trie is a data structure
#include <iostream> 
#include <vector>
using namespace std;
/*class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
     
     TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
     }
}; 
// here we write logic only for capital letters word;
class Trie{
    public:
    TrieNode* root;

    Trie(){
      root=new TrieNode('\0');
    }
    void insertUtil(TrieNode * root,string word){
      // base case
          if(word.length()==0){
            root->isTerminal=true;
            return;
          }
        // assumption world will be in caps
          int index=word[0]-'A';
          TrieNode* child;
          // present
          if(root->children[index]!=NULL){
                child=root->children[index];
          }
          // absent
          else{
              child=new TrieNode(word[0]);
              root->children[index]=child;
          }
          // recursion
          insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        //  TrieNode* root=NULL;
        insertUtil(root,word);
    }
 bool searchUtil(TrieNode* root,string word){
    //  base case
    if(word.length()==0){
      return root->isTerminal;
    }
    int index=word[0]-'A';
    TrieNode* child;
    // present
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
      // absent,agar pehla string ka character nhi hai toh aage kya khak milega
      return false;
    }
//  recursion
return searchUtil(child,word.substr(1));
 }
 bool search(string word){
  // TrieNode* root=NULL;
     return searchUtil(root,word);
 }
//  for prefix
 bool prefixUtil(TrieNode* root,string word){
    //  base case
    if(word.length()==0){
      return true;
    }
    int index=word[0]-'A';
    TrieNode* child;
    // present
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
      // absent,agar pehla string ka character nhi hai toh aage kya khak milega
      return false;
    }
//  recursion
return prefixUtil(child,word.substr(1));

 }
 
 bool startwith(string prefix){
  // TrieNode* root=NULL;
     return prefixUtil(root,prefix);
 }
//  deletion  homework hai


};
// longest common prefix
// approch 1 without using trie
string longestCommonPrefix(vector<string> &arr,int n){
  string ans="";
  // for traversal of first string
    for(int i=0;i<arr[0].length();i++){
       char ch=arr[0][i];
       bool match=true;
      //  for comparing char with rest of string
       for(int j=1;j<n;j++){
        //  not match
        if(arr[j].size()<1 || ch!=arr[j][i]){
          match=false;
          break;
        }
       }
       if(match==false)
          break;
       else
          ans.push_back(ch);
    }
    return ans;
} 

int main(){
   Trie *t=new Trie();
   t->insertWord("ABCD");
   cout<<"Present or Not "<<t->search("ABCD");
   cout<<"True or false "<<t->startwith("AC")<<endl<<endl;
   vector<string> arr;
   arr.push_back("coding");
   arr.push_back("codiz");
   arr.push_back("codi");
   cout<<longestCommonPrefix(arr,3);
    return 0;
}


class TrieNode{
  public: 
  char data;
  TrieNode* children[26];
  int childCount;
  bool isTerminal;
    TrieNode(char ch){
      data=ch;
      for(int i=0;i<26;i++)
        children[i]=NULL;
      isTerminal=false;
      childCount=0;
    }
};
class Trie{
  public:
  TrieNode* root;
  Trie(char ch){
    root=new TrieNode(ch);
  }
void insertUtil(TrieNode* root,string word){
  // base case
  if(word.length()==0){
    root->isTerminal=true;
    return;
  }
  int index=word[0]-'a';
  TrieNode* child;
  if(root->children[index]!=NULL){
    child=root->children[index];
  }
  else{
    child=new TrieNode(word[0]);
    root->childCount++;
    root->children[index]=child;
  }
  // recursive call
  insertUtil(child,word.substr(1));
  }
void insertWord(string word){
   insertUtil(root,word);
}
void lcp(string str,string &ans){
   for(int i=0;i<str.length();i++){
    char ch=str[i];
    if(root->childCount==1){
      ans.push_back(ch);
      // aage badh jao
      int index=ch-'a';
      root=root->children[index];
    }
    else{
      break;
    }
    if(root->isTerminal)
      break;
    
   }
}
};

string longestCommonPrefix(vector<string> &arr,int n){
  Trie *t=new Trie('\0');
  // insert kardo all string into trie
  for(int i=0;i<n;i++){
    t->insertword(arr[i]);
  }
  string first=arr[0];
  string ans="";
  t->lcp(first,ans);
  return ans;
}
*/


// phone diretory
  2
class TrieNode{
  public:
   char data;
   TrieNode* children[26];
   bool isTerminal;
   TrieNode(char ch){
    data=ch;
    for(int i=0;i<26;i++){
      children[i]=NULL;
    }
    isTerminal=false;
   }
}
class Trie{
  public:
  TrieNode* root;
  Trie(char ch){
    root=new TrieNode(ch);
  }
void insertUtil(TrieNode* root,string word){
  // base case
  if(word.length()==0){
    root->isTerminal=true;
    return;
  }
  int index=word[0]-'a';
  TrieNode* child;
  if(root->children[index]!=NULL){
    child=root->children[index];
  }
  else{
    child=new TrieNode(word[0]);
    root->childCount++;
    root->children[index]=child;
  }
  // recursive call
  insertUtil(child,word.substr(1));
  }
void insertWord(string word){
   insertUtil(root,word);
}};
void printsuggestion(TrieNode* curr,vector<string> &temp,string prefix){
  if(curr->isTerminal){
    temp.push_back(prefix);
    return;
  }
  for(char ch='a';ch<='z';ch++){
    TrieNode* next=curr->children[ch-'a'];
    if(nect!=NULL){
      prefix.push_back(ch);
      printsuggestion(nect,temp,prefix);
      prefix.pop_back();
    }
  }
}
vector<vector<string>> getsuggestion(string str){
  TrieNode* prev=root;
  vector<vector<string>> output;
  string prefix="";
  for(int i=0;i<str.length();i++){
     char lastch=str[i];
     prefix.push_back(lastch);

    //  check for last character
    TrieNode* curr=prev->children[lastch-'a'];
    // if not found
    if(curr==NULL){
      break;
    }
    // if found
    vector<string> temp;
    printsuggestion(curr,temp,prefix);
    output.push_back(temp);
    temp.clear();
    prev=curr;
      }
      return output;
}

vector<vector<string>> phoneDirectory(vector<string> &contactlist,string &queryStr){
  // creation of trie
  Trie *t=new Trie('\0');
  // insert all contact in trie
  for(int i=0;i<contactlist.size();i++){
    string str=contantlist[i];
    t->insertword(str);
  }
  // return ans
  return getsuggestion(queryStr);
}



int main(){
   Trie *t=new Trie('\0');
   t->insertWord("abcd");
   cout<<t-
    return 0;
}