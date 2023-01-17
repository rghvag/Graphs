#include <bits/stdc++.h> 
void toposortDFS(unordered_map<int,vector<int>> &adj, vector<bool> &visited,int node,stack<int> &s){
    visited[node]=1;
    for(auto i:adj[node]){
        if(visited[i]!=true){
            toposortDFS(adj,visited,i,s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //adjacency list
    unordered_map<int,vector<int> > adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
       adj[u].push_back(v);    
    }
    stack<int> s;
    vector<bool> visited(v,0);
    for(int i=0;i<v;i++){
        if(visited[i]!=true){
            toposortDFS(adj,visited,i,s);
            
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
