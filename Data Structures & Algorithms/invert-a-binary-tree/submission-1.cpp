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
        queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()){
            TreeNode* front = bfs.front();
            bfs.pop();
            swap(front->left,front->right);
            if(front->left) bfs.push(front->left);
            if(front->right) bfs.push(front->right);
        }

        return root;
    }
};
