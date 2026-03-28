#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(Node* root) {
    queue<pair<Node*, int>> q;
    map<int, int> m;

    q.push({root, 0});

    while(q.size()>0) {
        Node* curr = q.front().first;
        int currHT = q.front().second;

        q.pop();

        if(m.find(currHT) == m.end()) {
            m[currHT] = curr->data;
        }

        if(curr->left != NULL) {
            q.push({curr->left, currHT-1});
        }
        if(curr->right != NULL) {
            q.push({curr->right, currHT+1});
        }
    }

    for(auto it: m) {
        cout<<it.second<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);
    topView(root);
    return 0;
}