#include <iostream>
#include <queue>
using namespace std;

static int index = -1;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int data) {
            this->data = data;
        }
};

void preorder_traversal(Node* root) {
    if(root == NULL) {
        return;
    } else {
        cout << root->data << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(Node* root) {
     if(root == NULL) {
        return;
    } else {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->data << " ";
    }
}

void inorder_traversal(Node* root) {
    if(root == NULL) {
        return;
    } else {
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

void levelorder_traversal(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(q.size() > 0) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }  
    } 
}

Node* build_tree(int arr[]) {
    index += 1;
    if(arr[index] == -1) { 
        return NULL;
    } else {
        Node* newNode = new Node(arr[index]);
        newNode->left = build_tree(arr);
        newNode->right = build_tree(arr);
        return newNode;
    }
} 

int main() {
    int arr[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, -1};
    Node* root = build_tree(arr);
    preorder_traversal(root);
    cout << endl;
    postorder_traversal(root);
    cout << endl;
    inorder_traversal(root);
    return 0;
}