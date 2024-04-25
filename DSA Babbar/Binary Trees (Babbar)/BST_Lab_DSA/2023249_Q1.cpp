// Kth Largest Node in BST 
#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* right;
    Node* left;

    Node(int d){
        this -> val = d;
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

int solve(Node* root, int& i, int& k ){
        if (root == NULL){
            return -1;
        }
        int left = solve(root -> left, i, k);
        if (left != -1){
            return left;
        }
        i++;
        if (i==k){
            return root -> val;
        }
        return solve(root -> right, i, k);
};

int kthSmallest(Node* root, int k) {
        int i = 0; 
        int ans = solve(root, i, k);
        return ans;
};

int main() {
    Node* root = NULL;
    root = BuildTree(root);

    int k; 
    cout << "Enter the Value of k" << endl;
    cin >> k;

    cout << kthSmallest(root, k) << endl;
}


