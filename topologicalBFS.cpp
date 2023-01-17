#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //adjacency list
    vector<int > indegree(v);
    unordered_map<int,vector<int> > adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v); 
        indegree[v]++;
    }
    //0 indegree wale push
    queue<int> q;
    
    for(int i=0;i<v;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int> ans;
    
    //bfs
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        ans.push_back(front);
        
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}
