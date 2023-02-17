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
   vector<int>in;
   void ans_finder(TreeNode* root)
   {
    //    stack<int>s;
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
           TreeNode* top = q.front();
           q.pop();
           in.push_back(top->val);
           if(top->left) q.push(top->left);
           if(top->right) q.push(top->right);
       }
   }
    int minDiffInBST(TreeNode* root) {
        ans_finder(root);
        sort(in.begin(),in.end());
        int mn=INT_MAX;
        for(int i=0;i<in.size()-1;i++)
        {
            mn=min(in[i+1]-in[i],mn);
        }
        return mn;
    }
};