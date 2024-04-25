#include <iostream>
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

Node* BuildTree(Node* root){
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1){
        return NULL;
    }
    cout << "Insert Element at left" << endl;
    root -> left = BuildTree(root -> left);
    cout << "Insert Element at right" << endl;
    root -> right = BuildTree(root -> right);
}

// Creating function for Level Order Traversal (BFS)
void levelOrderTraversal(Node* root){
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

void InorderTraversal(Node* root){
    // Base case 
    if (root == NULL){
        return;
    }
    InorderTraversal(root -> left);
    cout << root -> data << " ";
    InorderTraversal(root -> right);
}
void PreOrder(Node* root){
    // Base case 
    // NLR
    if (root == NULL){
        return;
    }
    cout << root -> data << " ";
    PreOrder(root -> left);
    PreOrder(root -> right);
}


void PostOrder(Node* root){
        // Base case 
    if (root == NULL){
        return;
    }
    PreOrder(root -> left);
    PreOrder(root -> right);
    cout << root -> data << " ";
}

Node* buildFromLevelOrder(Node* root){
    queue<Node*>q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter left Node for :" << temp -> data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cin >> rightData;
        if (rightData != -1){
            temp -> left = new Node(rightData);
            q.push(temp->left);
        }

    }
}
int main() {
    Node* root = NULL;
    root = BuildTree(root);

    cout << "Printing BFS" << endl;
    levelOrderTraversal(root);
    

    cout << "Printing Inorder" << endl;
    InorderTraversal(root);

    cout << "Printing Pre-order" << endl;
    PreOrder(root);

    
    cout << "Printing Post-order" << endl;
    PostOrder(root);

    return 0;
}

