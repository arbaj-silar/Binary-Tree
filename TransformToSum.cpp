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

int search(vector<int>& in, int left, int right, int val) {
    for(int i=left; i<=right; i++) {
        if(in[i] == val) return i;
    }
    return -1;
}

Node* helper(vector<int>& pre, vector<int>& in, int& preIdx, int left, int right) {
    if(left>right) return NULL;
    Node* root = new Node(pre[preIdx]);
    preIdx++;
    
    int inIdx = search(in, left, right, root->data);
    root->left = helper(pre, in, preIdx, left, inIdx-1);
    root->right = helper(pre, in, preIdx, inIdx+1, right);

}

Node* buildTree(vector<int>& pre, vector<int>& in) {
    int preIdx = 0;

    helper(pre, in, preIdx, 0, in.size()-1);
}

int sumTree(Node* root) {
    if(root == nullptr) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    root->data += leftSum+rightSum;

    return root->data;
}

void preOrderTraversal(Node* root) {
    if(root == nullptr) return;

    cout<<root->data<<" ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};

    Node* root = buildTree(pre, in);
    cout<<sumTree(root);
    preOrderTraversal(root);
    cout<<endl;
    return 0;
}