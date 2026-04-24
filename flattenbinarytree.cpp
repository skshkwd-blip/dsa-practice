// Problem: Flatten Binary Tree to Linked List

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode* nextRight = NULL;//last visited

    void flatten(TreeNode *root){
        if(root == NULL){
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};

TreeNode* buildTree(vector<int> vals){
    if(vals.empty()) return NULL;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(vals[0]);
    q.push(root);
    int i = 1;
    while(!q.empty() && i < vals.size()){
        TreeNode* curr = q.front(); q.pop();
        if(i < vals.size() && vals[i] != -1){ // -1 used for null
            curr->left = new TreeNode(vals[i]);
            q.push(curr->left);
        }
        i++;
        if(i < vals.size() && vals[i] != -1){
            curr->right = new TreeNode(vals[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Print flattened tree
void printFlattened(TreeNode* root){
    while(root){
        cout << root->val;
        if(root->right) cout << " -> ";
        root = root->right;
    }
    cout << endl;
}

int main(){
    // Example: root = [1,2,5,3,4,null,6]
    // Use -1 for null
    vector<int> vals = {1,2,5,3,4,-1,6};
    TreeNode* root = buildTree(vals);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened tree: ";
    printFlattened(root);
    return 0;
}