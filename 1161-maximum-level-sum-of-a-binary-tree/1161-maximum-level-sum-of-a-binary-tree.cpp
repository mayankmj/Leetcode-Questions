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
    int bfs(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        int ans=INT_MIN,tempSum=0,lvl=0,count=1;
        while(!q.empty())
        {
            tempSum=0;
            int ss=q.size();
            for(int i=0;i<ss;i++)
            {
                auto x = q.front();
                q.pop();
                tempSum+=x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            if(tempSum>ans){
                ans=tempSum;
                lvl=count;
            }
            count++;
        }
        return lvl;
    }
    int maxLevelSum(TreeNode* root) {
          return bfs(root);
    }
};