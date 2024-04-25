#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjacency, vector<vector<int>> &adj){
    for (int i = 0; i<adj.size(); i++){
        int u = adj[i][0];
        int v = adj[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adjacency, unordered_map<int, list<int>> &visited, vector<int>&ans, int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);
        for (auto i : adjList[frontNode]){
            if (visited[i] != 1){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    unordered_map<int, list<int>> adjacency;
    vector<int>ans;
    unordered_map<int, list<int>> visited;
    prepareAdjList(adjacency, adj);

    for (int i = 0; i<vertex; i++){
        if (!visited[i]){
            bfs(adjacency, visited, ans, i );
        }
    }
    return ans;
}