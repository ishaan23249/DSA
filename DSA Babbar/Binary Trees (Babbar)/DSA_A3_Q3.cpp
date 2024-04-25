#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int d){
        this -> data = d;
        this -> right = NULL;
        this -> left = NULL;
    }
};

Node* TreeBuild(vector<int>& level){
    if (level.empty()){
        return NULL;
    }
    Node* root = new Node(level[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i<level.size()){
        Node* temp = q.front();
        q.pop();

        int left = levelOrder[i++]
    }

}
int main () {
    vector<string>v;
    int n;
    
}

