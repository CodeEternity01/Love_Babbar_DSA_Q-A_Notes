#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

class graph{
    public:
    
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,int direction){
        // if direction=0 means undirected
        // if direction=1 means directed

        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void print(){

        for(auto i: adj){
            cout<<i.first<<"-->";
            for(auto it : i.second){
                cout<<it<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){

    int n;
    cout<<"enter no node"<<endl;
    cin>>n;

    int m;
    cout<<"enter no of edges"<<endl;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
       int u,v;
       cin>>u>>v;

       g.addEdge(u,v,0);
    }
    g.print();

    
    return 0;
}



