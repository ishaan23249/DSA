#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>

class graph{
public:
   unordered_map<T, list<T>> adj;

   void addEdge(T u, T v, bool direction){
    // Direction = 0 -> undirected 
    // Direction = 1 -> directed graph
    // Create an edge from u to v
    // IIIT Delhi, CSAI '
    adj[u].push_back(v);
    if (direction == 0){
        adj[v].push_back(u);
    }
   }
   void print(){
    for (auto i : adj){
        cout << i.first << "->";
        for (auto j : i.second){
            cout << j << ", ";
        }
        cout << endl;
    }
   }
};

int main () {
    int n;
    cout << "Enter Number of Nodes :- " << " ";
    cin >> n;
    int m;
    cout << "Enter Number of Edges :- " << " ";
    cin >> m;

    graph<int> g;
    for (int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        // Creating an Undirected Graphs 
        g.addEdge(u, v, 0);
    }

    g.print();
    
}
