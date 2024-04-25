#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
// Using Kahn's Algorithm. 
// Create Adjacency list. 
unordered_map<int, list<int>> adj;
vector<int>indeg(v, 0);
for (int i = 0; i < edges.size(); i++) {
  int u = edges[i][0];
  int v = edges[i][1];
  adj[u].push_back(v) ;
  indeg[v]++;
}

int main {

queue<int>q;
for (int i = 0; i<v; i++){
    if (indeg[i]==0){
        q.push(i);
    }
}
}


vector<int>ans;
while(!q.empty()){
    int fr = q.front();
    q.pop();

    ans.push_back(fr);

    for (auto i : adj[fr]){
        indeg[i]--;
        if (indeg[i] == 0) {
          q.push(i);
        }
    } 
}
return ans;
}

