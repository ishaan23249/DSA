#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class Graph {
    public :
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        if (direction == 0){
            adj[v].push_back(u);
    }
    }
    void print(){
    for (auto i : adj){
        cout << i.first << "->";
        for (auto j : i.second){
            cout << j;
        }
        cout << endl;
     }
    }
};
int main (){
cout << "Enter No. of Edges" << endl;
int m;
cin >> m;

cout << "Enter No. of Nodes" << endl;
int n;
cin >> n;

Graph G;
    for (int i = 0; i<n; i++){
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v, 0);
    }
    G.print();
}