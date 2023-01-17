#include <bits/stdc++.h> 

void makeadjList(unordered_map<int,set<int>> &adjList,vector<pair<int, int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(vector<pair<int, int>> &edges,unordered_map<int,bool> &visited,unordered_map<int,set<int>> &adjList, vector<int> &ans,int node){
    
    queue<int> q;
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        
        ans.push_back(frontnode);
    
//     pushing all neighbours of node in queue if not visited
        for(auto i:adjList[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }    
    }
}

void print(unordered_map<int,set<int>> adjList){
    for(auto it : adjList){
        cout<<it.first<<"->";
        for(auto j: it.second){
            cout<<"j"<<" ";
        }
        cout<<endl;
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    
    makeadjList(adjList,edges);
//     print(adjList);
    unordered_map<int,bool> visited;
    
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(edges,visited,adjList,ans,i);
        }
    }
    return ans;

}
