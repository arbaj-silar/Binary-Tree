#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data; 
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> &preOrder) {
    idx++;
    if(preOrder[idx] == -1) return NULL;

    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

bool identical(Node* r1, Node* r2) {
    return identical(r1->left, r2->left) && identical(r1->right, r2->right) && r1->data == r2->data;
}
int main() {
    vector<int> p = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> q = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* r1 = buildTree(p);
    Node* r2 = buildTree(q);
    cout<<identical(r1, r2);
    return 0;
}