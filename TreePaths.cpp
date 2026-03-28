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


void allPaths(Node* root, string path, vector<string>& ans) {
    if(root->left == nullptr && root->right == nullptr) {
        ans.push_back(path);
        return;
    }

    if(root->left) {
        allPaths(root->left, path+"->"+to_string(root->left->data), ans);
    }

    if(root->right) {
        allPaths(root->right, path+"->"+to_string(root->right->data), ans);
    }
}

int main() {
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};

    Node* root = buildTree(pre, in);

    vector<string> ans;
    string path = to_string(root->data);

    allPaths(root, path, ans);
    for(string p: ans) {
        cout<<p<<endl;
    }
    return 0;
}