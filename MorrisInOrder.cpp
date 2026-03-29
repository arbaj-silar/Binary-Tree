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
    if(idx >= preOrder.size() || preOrder[idx] == -1) return NULL;

    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

vector<int> inorderTraversal(Node* root) {
    vector<int> ans;
    Node* curr = root;

    while(curr != nullptr) {
        if(curr->left != NULL) {
            ans.push_back(curr->data);
            curr = curr->right;
        } else {
            Node* IP = curr->left;
            while(IP->right != NULL && IP->right != curr) {
                IP = IP->right;
            }

            if(IP->right == NULL) {
                IP->right = curr;
                curr = curr->left;
            } else {
                IP->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
    
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    Node* root = buildTree(preOrder);

    vector<int> ans = inorderTraversal(root);
    cout<<ans.size();
    for(int a: ans) {
        cout << a <<endl;
    }
    return 0;
}