#include<iostream>
#include<vector>
#include<algorithm>
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

int treeHeight(Node* root) {
    if(root == nullptr) return 0;
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

int treeDiameter(Node* root) {
    if(root == nullptr) return 0;

    int lt = treeDiameter(root->left);
    int rt = treeDiameter(root->right);
    int curr = treeHeight(root->left)+treeHeight(root->right);
    return max(curr, max(lt, rt));
}

int ans = 0;

int height(Node* root) {
    if(root == nullptr) return 0;

    int lt = height(root->left);
    int rt = height(root->right);
    ans = max(ans, lt+rt);
    return max(lt, rt)+1;
}

int diameter(Node* root) {
    height(root);
    return ans;
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, -1, -1};

    Node* root = buildTree(preOrder);
    cout<<treeHeight(root)<<endl;
    cout<<treeDiameter(root)<<endl;
    cout<<diameter(root)<<endl;
    return 0;
}