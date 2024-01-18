#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
class graph{
    public:
    unordered_map<int,list<int>> adj;
    void addedge(int u,int v,bool direction){
       // direction=0 ->undirected graph
      // direction=1 ->directed graph
      // create an edge from u to v
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdjlist(unordered_map<int,list<int>> adj){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
/*
    int n;
    cout<<" Enter the number of node "<<endl;
    cin>>n;
    int m;
    cout<<" Enter the number of edge "<<endl;
    cin>>m;
    graph<int> g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // creating an directed graph
        g.addedge(u,v,0);
    }
    // pringting the graph
    g.printAdjlist();

*/
// adjency list
    void print(unordered_map<int,set<int>> adj){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
vector<vector<int>> printAdjacency(int n,int m,vector<vector<int>> &edge){
    vector<int> ans[n];
    for(int i=0;i<n;i++){
        int u=edge[i][0];
        int v=edge[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
        for(int j=0;j<ans[i].size();j++){
            adj[j].push_back(ans[i][j]);
        }
    }
    return adj;
}
// breadth first search
void prepareAdjlist(unordered_map<int,set<int>> &adjlist,vector<pair<int,int>> edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjlist[u].insert(v);
        adjlist[v].insert(u);

    }
}
void bfs(unordered_map<int,set<int>> &adjlist,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        // store in ans
        ans.push_back(frontNode);
        // traverse all node
        for(auto i:adjlist[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> BFS(int vertes,vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adjlist;
    vector<int> ans;
    unordered_map<int,bool> visited;
    // prepare adjency list
    prepareAdjlist(adjlist,edges);
    print(adjlist);
    // traverse all components of graph
    for(int i=0;i<vertes;i++){
        if(visited[i]){
            bfs(adjlist,visited,ans,i);
        }
    }
    return ans;
}
// Defth first search
// pehle gehraio me dund ke aao
void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,set<int>> &adj,vector<int> &component){
    component.push_back(node);
    visited[node]=true;
    // har connected mode ke liye recursive call
    for(auto i:adj[node]){
        if(!visited[i]){
            afs(i,visited,adj,component);
        }
    }
}
vector<vector<int>> depthFirstsearch(int V,int e,vector<vector<int>> &edges){
    // prepare adjlist
    unordered_map<int,set<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<V.size();i++){
        if(visited[i]){
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    } 
    return ans;
}
// cycle detection in undirected graph
// approch using bfs
bool iscyclicBFS(int src,unordered_map<int,bool> &visited, unordered_map<int,list<int>> adj){
   unorder_map<int,int> parent;

   parent[src]=-1;
   visited[src]=1;
   queue<int> q;
   q.push(src);
   while(!q.empty()){
    int front=q.front();
    q.pop();
    for(auto neighbour: adj[front]){
         if(visited[neighbour]==true && neighbour!=parent[front]){
            return true;
         }
         else if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour]=1;
            parent[neighbour]=front;
         }
    }
   }
   return false;
}
 string cycleDetection(vector<vector<int>> &edges,int n,int m){
    // n=number of node,m=no of edges
    // create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<n;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // to handle disconnected commponent
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=iscyclicBFS(i,visited,adj);
            if(ans==1){
                return 'Yes';
            }
        }
    } 
    return "No"; 
 }

// cycle detection of undirected graph using DFS
  bool iscyclicDFS(int src,int parent,unordered_map<int,bool> &visited, unordered_map<int,list<int>> adj){

   visited[src]=1;
 
  for(auto neighbour: adj[src]){
          if(!visited[neighbour]){
          bool cycledetected=iscyclicDFS(neighbour,src,visited,adj);
          if(cycledetected){
            return true;
          }
          }
          else if(neighbour!=parent){
                return true;
          }
    }
   
   return false;
}
 string cycleDetection(vector<vector<int>> &edges,int n,int m){
    // n=number of node,m=no of edges
    // create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<n;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // to handle disconnected commponent
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=iscyclicDFS(i,-1,visited,adj);
            if(ans==1){
                return 'Yes';
            }
        }
    } 
    return "No"; 
 } 
  

int main(){

    return 0;
}