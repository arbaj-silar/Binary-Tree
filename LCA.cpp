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

Node* findNode(Node* root, int val) {
    if(root == NULL) return NULL;
    if(root->data == val) return root;

    Node* left = findNode(root->left, val);
    if(left) return left;

    return findNode(root->right, val);
}

Node* buildTree(vector<int> &preOrder) {
    idx++;
    if(preOrder[idx] == -1) return NULL;

    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

Node* lca(Node* root,Node* p,Node* q) {
    // LCD : lowest common ancestor

    if(root == nullptr) return NULL;

    if(root->data == p->data || root->data == q->data) return root;
    Node* leftLCA = lca(root->left, p, q);
    Node* rightLCA = lca(root->right, p, q);

    if(leftLCA && rightLCA) return root;
    else if(leftLCA != NULL) return leftLCA;
    else return rightLCA;
}
int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);
    Node* p = findNode(root, 2);
    Node* q = findNode(root, 5);

    Node* ans = lca(root, p, q);
    cout<<ans->data<<endl;
    return 0;
}