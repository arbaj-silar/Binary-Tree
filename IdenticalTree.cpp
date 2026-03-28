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

Node* buildTree(vector<int> &p) {
    idx++;
    if(p[idx] == -1) return NULL;

    Node* root = new Node(p[idx]);

    root->left = buildTree(p);
    root->right = buildTree(p);

    return root;
}

bool identical(Node* r1, Node* r2) {
    if(r1 == NULL || r2 == NULL) return r1 == r2;
    return (identical(r1->left, r2->left) && identical(r1->right, r2->right) && r1->data == r2->data);
}

bool subTree(Node* r1, Node* r2) {
    if(r1 == nullptr || r2 == nullptr) return r1 == r2;

    if(r1->data == r2->data && identical(r1, r2)) return true;
    return subTree(r1->left, r2) || subTree(r1->right , r2);
}
int main() {
    vector<int> p = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* r1 = buildTree(p);
    Node* r2 = buildTree(p);
    cout<<identical(r1, r2);
    cout<<subTree(r1, r2);
    return 0;
}