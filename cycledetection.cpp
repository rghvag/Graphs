#include<bits/stdc++.h>
bool isCyclicBFS(int src,unordered_map<int,vector<int>> &adjList, unordered_map<int,bool> &visited){
    unordered_map<int,int> parent;
    queue<int> q;
    
    parent[src]=-1;
    visited[src]=1;
    q.push(src);
    
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        
        for(auto neighbour:adjList[frontnode]){
            if(visited[neighbour]==true && parent[frontnode]!=neighbour)             {
                return true;
            }
            else if(visited[neighbour]!=true){
                visited[neighbour]=1;
                parent[neighbour]=frontnode;
                q.push(neighbour);
            }
        }   
    }
    return false;
}

bool isCyclicDFS(int src,int parent,unordered_map<int,vector<int>> &adjList, unordered_map<int,bool> &visited){
    visited[src]=1;
    
    for(auto neighbour: adjList[src]){
        if(!visited[neighbour]){
            bool cycleP=isCyclicDFS(neighbour,src,adjList,visited);
            if(cycleP) return true;
        }
        else if(parent!=neighbour) return true;
    }
    return false;
    
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,vector<int>> adjList;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
    }
    //to handle disjoint components
    unordered_map<int,bool> visited;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCyclicDFS(i,-1,adjList,visited);
            if(ans==1){
                return "Yes";
            }
        }        
    }
    return "No";
}
