#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void levelOrderTraversal(Node* root){
    <vector<vector<int>> final_v;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()) {
                // queue still has some child nodes
                q.push(NULL);
            }
        }

        else{
            cout << temp -> data << " ";
            
            if(temp -> left){
            q.push(temp->left);
            }

            if (temp -> right){
            q.push(temp -> right);
            }
        }
    }
}
