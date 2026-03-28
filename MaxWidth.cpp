#include<iostream>
#include<vector>
#include<queue>
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

int maxWidthOfTree(Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int maxWd = 0;

    while(q.size()>0) {
        int currSize = q.size();
        int stIdx = q.front().second;
        int endIdx = q.back().second;

        maxWd= max(maxWd, endIdx-stIdx+1);

        for(int i=0; i<currSize; i++) {
            auto curr = q.front();
            q.pop();

            if(curr.first->left) {
                q.push({curr.first->left, 2*curr.second+1});
            }
            if(curr.first->right) {
                q.push({curr.first->right, 2*curr.second+2});
            }
        }
    }
    return maxWd;
}

int main() {
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};

    Node* root = buildTree(pre, in);
    cout<<"Max Width : "<<maxWidthOfTree(root)<<endl;
    return 0;
}