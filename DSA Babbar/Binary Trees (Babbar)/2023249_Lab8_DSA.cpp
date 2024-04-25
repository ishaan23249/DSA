#include <iostream>
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


Node* InsertIntoBST(Node* &root, int d){
    if (root == NULL){
        root = new Node(d);
        return root;
    }

    if (d > root -> data){
        root -> right = InsertIntoBST(root -> right,d);
 
    }
    else{
        root -> left = InsertIntoBST(root -> left,d);
    }

    return root;

}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while (data != -1){
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}
int minValue(Node* root){
    while (root -> left != NULL){
        root = root -> left;
    }
    return root->data;
}
Node* deletefromBST(Node* root, int val){
    // Base Case 
    if (root == NULL)
     return root;

    if (root -> data == val){
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
            return temp;
        }
        if (root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        // 2 child  
        if (root -> left != NULL && root -> right != NULL){
            int mini = minValue(root -> right);
            root -> data = mini;
            root -> right = deletefromBST(root -> right, mini);
            return root; 
        }
    }
    else if (root -> data > val){
        root -> left = deletefromBST(root -> left, val);
        return root;
    }
    else {
        root -> right = deletefromBST(root -> right, val);
        return root;
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

int calculateHeight(Node* root){
        if (root == NULL){
            return 0;
        }
        int right = calculateHeight(root -> right);
        int left = calculateHeight (root -> left);
        int max2 = max(right, left) + 1;

        return max2;
}

void Count(Node* root, int& count){
    if (root == NULL){
        return; 
    }
    count++;
    Count(root -> left, count);
    Count(root -> right, count);
}

int countNodes(Node* root) {
    // Calculate Total No. of Nodes in the BST. 
    int cnt = 0;
    Count(root, cnt);
    return cnt;
}

int main() {
    Node* root = NULL;
    cout << "Enter Data for creating BST" << endl;
    takeInput(root);
    InorderTraversal(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    cout << countNodes(root);
    cout << endl;
    cout << calculateHeight(root)-1;
    cout << endl;
    deletefromBST(root, 2);
    InorderTraversal(root);

}
