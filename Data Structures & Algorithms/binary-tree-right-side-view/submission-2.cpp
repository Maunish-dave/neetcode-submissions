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
        if(!root) return {};
        vector<int> answer;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            answer.push_back(q.front()->val);
            int s = q.size();
            while(s--){
                TreeNode* top = q.front();
                q.pop();
                if(top->right) q.push(top->right);
                if(top->left) q.push(top->left);
            }
        }

        return answer;

    }
};
