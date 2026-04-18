// Problem: Binary Tree Inorder Traversal (LeetCode)
// Approach: Morris Traversal (Threaded Binary Tree)

#include<iostream>
#include<vector>
#include<queue>
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
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            } else{
                //find IP
                TreeNode* IP = curr->left;
                while(IP->right != NULL && IP->right != curr){
                    IP = IP->right;
                }

                if(IP->right == NULL){
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

TreeNode* buildTree(vector<int> nodes){
    if(nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < nodes.size()){
        TreeNode* curr = q.front(); q.pop();
        if(i < nodes.size() && nodes[i] != -1){
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if(i < nodes.size() && nodes[i] != -1){
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main(){
    vector<int> arr = {1,2,3,4,5,-1,8,-1,-1,6,7,9};

    TreeNode* root = buildTree(arr);

    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}