#include <bits/stdc++.h>
using namespace std;

unordered_map<int, list<int>> prepareAdjList(vector<vector<int>> &adj){
    unordered_map<int, list<int>> Adjlist;
    for (int i = 0; i<adj.size(); i++){
        
        int u = adj[i][0];
        int v = adj[i][1];
        
        Adjlist[u].push_back(v);
        Adjlist[v].push_back(u);
    }
    return Adjlist;
}

void DeletefromAdj(unordered_map<int, list<int>> &Adjlist, int key){
    Adjlist.erase(key);
}

void PrepareAdjMat(vector<vector<int>> &AdjMat, vector<vector<int>> &adj){
    for (int i = 0; i<adj.size(); i++){
        int u = adj[i][0];
        int v = adj[i][1];
        AdjMat[u][v] = 1;
        // if undirected. 
        AdjMat[v][u] = 1;
    }
}

void bfs(unordered_map<int, list<int>> &adjacency, unordered_map<int, int> &visited, vector<int>&ans, int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);
        for (auto i : adjacency[frontNode]){
            if (visited[i] != 1){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
void DFStraversal(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &component, int node) {
    component.push_back(node);
    visited[node] = 1;

    for(auto i : adjList[node]) {
        if(!visited[i]) {
            // recursion
            DFStraversal(adjList, visited, component, i);
        }
    }

}
vector<int> bfsTraversal(vector<vector<int>> &adj){
    unordered_map<int, list<int>> adjacency;
    vector<int>ans;
    unordered_map<int, bool> visited;
    prepareAdjList(adjacency, adj);

    for (int i = 0; i<adj.size(); i++){
        if (visited[i] == 1){
            bfs(adjacency, visited, ans, i );
        }
    }
    return ans;
}


vector<int> DFSTraversal(unordered_map<int, list<int>> &adjacency){
    for(int i=0; i<V; i++) {
        if(!Visited[i]) {
            vector<int> component;
            traversal(adjacency, visited, component, i);
            answer.push_back(component);
        }
    }
}


int main () {
    int n = 4;
    // 1, 2, 3, 4
    vector<vector<int>> v;
    vector<int>v1 = {1, 2};
    vector<int>v2 = {2, 3};
    vector<int>v3 = {3, 1};
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    

}