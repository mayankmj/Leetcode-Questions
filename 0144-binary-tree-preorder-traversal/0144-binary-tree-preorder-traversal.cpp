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
    void ans_finder(vector<int>&ans,TreeNode* root)
    {
        if(!root) return ;
        ans.push_back(root->val);
        if(root->left) ans_finder(ans,root->left);
        if(root->right) ans_finder(ans,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        ans_finder(ans,root);
        return ans;
    }
};