#include <bits/stdc++.h> 
#include <unordered_map>
#include <stack>
void topSort(int node, unordered_map<int, bool>& Visited, stack<int>&s, unordered_map<int, list<int>>& adj){
    visited[node] = 1;
    for (auto neighbour : adj[node]){
        if (!visited[neighbour]){
            topSort(neighbour, Visited, s, adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i<edges.size(), i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    unordered_map<int, bool> Visited;
    stack<int>s;
    for (int i = 0; i<n; i++){
        if (!visited[i])
         topSort(i , visited, s, adj);
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
