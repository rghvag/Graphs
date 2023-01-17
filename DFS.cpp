#include<bits/stdc++.h>
void dfs(int node,unordered_map<int,vector<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans){

    ans.push_back(node);
    visited[node]=1;
    
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,adjList,visited,ans);
        }
    }   
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
   unordered_map<int,vector<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int,bool> visited;
    vector<vector<int> > ans;
    for(int i=0;i<V;i++){
        if( visited[i] !=true){
            vector<int> component;
            dfs(i,adjList,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}
