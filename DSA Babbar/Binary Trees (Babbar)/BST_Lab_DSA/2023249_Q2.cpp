#include <iostream>
#include <climits>
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


bool isBST(Node* root, long long min, long long max){
    if (root == NULL)
      return true;
    
    if (root -> val > min && root -> val < max){
        bool left = isBST(root -> left, min, root -> val );
        bool right = isBST(root -> right, root -> val, max);
        return left && right;
    }
    else 
      return false;
}
bool isValidBST(Node* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
}

int main() {
    Node* root = NULL;
    root = BuildTree(root);

    if(isValidBST(root)){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
