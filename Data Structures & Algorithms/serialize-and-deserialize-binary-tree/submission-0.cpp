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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "-1001";
        string s = to_string(root->val);
        string l = serialize(root->left);
        string r = serialize(root->right);

        return s + "#" + l + "#" + r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << data << endl;
        vector<int> nums;
        stringstream ss(data);
        string token;

        while(getline(ss,token,'#')){
            if(!token.empty()) nums.push_back(stoi(token));
        }

        int i = 0;

        return dfs(nums,i);
        
    }

    TreeNode* dfs(vector<int> nums, int &i){
        if(nums[i]==(-1001)){
            i++;
            return nullptr;
        };
        TreeNode* node = new TreeNode(nums[i++]);
        node->left = dfs(nums,i);
        node->right = dfs(nums,i);
        return node;
    }
};
