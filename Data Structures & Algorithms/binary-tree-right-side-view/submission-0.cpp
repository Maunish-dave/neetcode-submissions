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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        unordered_map<int,TreeNode*> hash;
        int level = 0;
        dfs(root, hash, level, answer);
        return answer;
    }

    void dfs(TreeNode* root, unordered_map<int,TreeNode*> &hash, int level, vector<int> &answer){
        if (!root) return;

        if(hash.find(level)==hash.end()){
            answer.push_back(root->val);
            hash[level] = root;
        }

        dfs(root->right, hash, level+1, answer);
        dfs(root->left, hash, level+1, answer);
    }
};
