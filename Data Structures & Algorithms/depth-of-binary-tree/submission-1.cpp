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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        stack<pair<TreeNode*,int>> stc;
        stc.push({root,1});
        int res = 0;

        while(!stc.empty()){
            pair<TreeNode*,int> current = stc.top();
            stc.pop();
            TreeNode* node = current.first;
            int depth = current.second;
            res = max(res,depth);
            if(node->left) stc.push({node->left,depth+1});
            if(node->right) stc.push({node->right,depth+1});
        }

        return res;
    }
};
