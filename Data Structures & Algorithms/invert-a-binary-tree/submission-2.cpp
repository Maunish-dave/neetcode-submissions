/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        stack<TreeNode*> stc;
        stc.push(root);

        while(!stc.empty()){
            TreeNode* node = stc.top();
            stc.pop();
            swap(node->left,node->right);
            if(node->left) stc.push(node->left);
            if(node->right) stc.push(node->right);
        }

        return root;
    }
};
