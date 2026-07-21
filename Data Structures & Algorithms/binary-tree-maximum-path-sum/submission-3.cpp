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
    int maxPathSum(TreeNode* root) {
        int answer = INT_MIN;
        dfs(root,&answer);
        return answer;
    }

    int dfs(TreeNode* root,int *answer){
        if(root==nullptr) return INT_MIN;

        int left = dfs(root->left,answer);
        int right = dfs(root->right,answer);


        left = (left>0) ? left : 0;
        right = (right>0) ? right : 0;

        *answer = max(*answer,root->val + (left + right));

        return max(root->val + left, root->val + right);
    }
};
