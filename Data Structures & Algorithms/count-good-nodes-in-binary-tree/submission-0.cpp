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
    int goodNodes(TreeNode* root) {
        int answer = 0;
        int max = -101;
        dfs(root,answer,max);
        return answer;
    }

    void dfs(TreeNode* root, int &answer, int max){
        if(!root) return;

        if(root->val >= max){
            answer++;
            max = root->val;
        }

        dfs(root->right,answer,max);
        dfs(root->left,answer,max);
    }
};
