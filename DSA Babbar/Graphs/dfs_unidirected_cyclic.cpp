#include <unordered_map>
#include <list>
#include <vector>


bool checkDFSCyclic(int node, unordered_map<int, bool>&visited, unordered_map<int, bool>&DFSvisited, unordered_map<int, list<int>> &adj){
    visited[node] = true;
    DFSvisited[node] = true;

    for (auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool CycleDetected = checkDFSCyclic(neighbour, visited, DFSvisited, adj);
            if (CycleDetected)
             return true;
        }
        else if (visited[neighbour]){
            return true;
        }
    }
    visited[node] = false;
    return false;
    
} 
int detectCycleInDirectedGraph(int n, vector <pair<int,int>>&edges) {
//   Creating Adjacency List
unordered_map<int, list<int>> adj;
for (int i = 0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
}
unordered_map<int, bool>visited;
unordered_map<int, bool>DFSvisited;

for (int i = 0; i<n; i++){
    if (!visited[i]){
        bool cycleFound= checkDFSCyclic(i, visited, DFSvisited, adj);
        if (cycleFound){
            return true;
        }
    }
}
return false;
}