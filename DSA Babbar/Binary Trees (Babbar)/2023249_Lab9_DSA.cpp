// LAB - 9 (06 April 2024) DSA 
// Ishaan Shekhar, 2023249
// IMPLEMENTATION OF AVL TREE 
// insertion in avl tree, deletion in avl tree, search key in avl tree

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;
    int height;

    Node(int d){
        this -> data = d;
        this -> right = NULL;
        this -> left = NULL;
        this -> height = 1;
    }
};



int height(Node* root){
        if (root == NULL){
            return 0;
        }
        return root->height;
}

    // Creating attribute Balance Factor.
int Balance_F(Node* root){
        if (root == NULL){
            return 0;
        }
        return height(root -> right) - height(root -> left);
}
Node* RotateRight(Node* root){
        Node* l = root -> left;
        Node* lr = l -> right;

        l -> right = root;
        root -> left = lr;

        root -> height = 1 + max(height(root -> left), height(root -> right));
        l -> height = 1 + max(height(l -> left), height(l -> right));

        return l;
}    
Node* Rotateleft(Node* root){
        Node* r = root -> right;
        Node* rl = r -> left;

        r -> left = root;
        root -> right = rl;

        root -> height = 1 + max(height(root -> left), height(root -> right));
        rl -> height = 1 + max(height(rl -> left), height(rl -> right));

        return r;
}

Node* InsertintoAVL(Node* &root, int key){
        // First do normal BST Operations. 
        if (root == NULL){
            return new Node(key); 
        }
        if (key < root -> data){
            root -> left = InsertintoAVL(root -> left, key);
        }
        else {
            root -> right = InsertintoAVL(root -> right, key);
        }

        root -> height = (1 + max(height(root -> right), height(root -> left)));

        // Now use Balance Factor to Implement all cases 
        int BF = Balance_F(root);
        int BF_L = Balance_F(root -> left);

        // We will deal with 4 cases, LL, LR,RL, RR. 
        if (BF < -1){
            if (BF_L < 0){
                // LL Case. 
                return RotateRight(root);
            }
            else {
                // LR Case. 
                root->left = Rotateleft(root->left);
                return RotateRight(root);
            }
        }

        if (BF > 1){
            if (BF_L > 0) {
                // RR Case. 
                return Rotateleft(root);
            }
            else {
                // RL Case
                root -> right = RotateRight(root);
                return Rotateleft(root);

            }
        }
        return root;
}

Node* SearchinAVL(Node* root, int key){
        if (root == NULL || root->data == key){
            return root;
        }
        if (key > root -> data){
            return SearchinAVL(root -> right, key);
        }
        else {
            return SearchinAVL(root -> left, key);
        }
}

    // Node* Delete_from_AVL(Node*root, int key){
    //     // We do simple BST Deletion and then perform balancing operations for this process. 

    // }
void InorderTraversal(Node* root){
    // Base case 
    if (root == NULL){
        return;
    }
    InorderTraversal(root -> left);
    cout << root -> data << " ";
    InorderTraversal(root -> right);
}

int minValue(Node* root){
    while (root -> left != NULL){
        root = root -> left;
    }
    return root->data;
}


Node* deleteinAVL(Node* root, int key){
    // First we will do deletion in BST & Then perform rotations.
    if (root == NULL)
     return root;

    if (root -> data == key){
        // 0 child
        if (root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        // 1 child 
        // Left Child 
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
        }
        if (root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
        }
        // 2 child  
        if (root -> left != NULL && root -> right != NULL){
            int mini = minValue(root -> right);
            root -> data = mini;
            root -> right = deleteinAVL(root -> right, mini);    
        }
    }
    else if (root -> data > key){
        root -> left = deleteinAVL(root -> left, key);
    }
    else {
        root -> right = deleteinAVL(root -> right, key);
    }

    root -> height = (1 + max(height(root -> right), height(root -> left)));

        // Now use Balance Factor to Implement all cases 
        int BF = Balance_F(root);
        int BF_L = Balance_F(root -> left);

        // We will deal with 4 cases, LL, LR,RL, RR. 
        if (BF < -1){
            if (BF_L < 0){
                // LL Case. 
                return RotateRight(root);
            }
            else {
                // LR Case. 
                root->left = Rotateleft(root->left);
                return RotateRight(root);
            }
        }

        if (BF > 1){
            if (BF_L > 0) {
                // RR Case. 
                return Rotateleft(root);
            }
            else {
                // RL Case
                root -> right = RotateRight(root);
                return Rotateleft(root);

            }
        }
        return root;


}

int main() {
    Node* root = NULL;
    root = InsertintoAVL(root, 3);
    root = InsertintoAVL(root, 5);
    root = InsertintoAVL(root, 1);
    root = InsertintoAVL(root, 9);
    InorderTraversal(root);
}