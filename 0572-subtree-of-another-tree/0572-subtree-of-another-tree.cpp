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
    bool flag = 0;
    bool is_equal(TreeNode* a ,  TreeNode* b)
    {
        if(!a && !b) return 1;
        if(!a || !b) return 0;

        if(a->val == b->val){
            bool ans1 = is_equal(a->left,b->left);
            bool ans2 = is_equal(a->right,b->right);
            if(ans1 && ans2) return 1;
        }
        return 0;
    }
    void dfs(TreeNode* root  , TreeNode* subRoot)
    {
        if(!root) return;
        if(root->val == subRoot->val && !flag) flag = is_equal(root,subRoot);

        if(root->left) dfs(root->left,subRoot);
        if(root->right) dfs(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root , subRoot);
        return flag;
    }
};