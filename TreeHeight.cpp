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

int heightOfTree(Node* root) {
    if(root == nullptr) return 0;

    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

int nodeCount(Node* root) {
    if(root == nullptr) return 0;

    return nodeCount(root->left)+nodeCount(root->right)+1;
}

int sumOfNode(Node* root) {
    if(root == nullptr) return 0;

    return sumOfNode(root->left)+sumOfNode(root->right)+root->data;
}
int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);
    cout<<"Height : "<<heightOfTree(root)<<endl;
    cout<<"No. of Node : "<<nodeCount(root)<<endl;
    cout<<"Sum of Node : "<<sumOfNode(root)<<endl;
    
    return 0;
}