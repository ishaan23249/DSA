#include <unordered_map>
#include <queue>
#include <list>
#include <vector>

bool isCyclicBFS(int src, unordered_map<int, bool>&visited,unordered_map<int, list<int>> adj ){
    visited[src] = 1;
    queue<int>q;
    q.push(src);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front]){
            if (visited[neighbour] == true)
            {
                return true;
            }
            else if (!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
    return false;
}
bool cycleDetection (int n, vector<vector<int>>& edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    for (int i = 0; i<n; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adj);
            if (ans == 1){
                return true;
            }
        }
       
    }
    return false;
    
}
