class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>ans;
        

        int left=0 , right = m-1;
        int top = 0 , buttom = n-1;
        // left -> right 
        // right -> buttom
        // buttom -> left
        //  left -> top
        while(1){
        if(left > right) break;
        for(int i=left;i<=right;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        if(top > buttom ) break;
        for(int i=top;i<=buttom;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(left>right ) break;
        for(int i=right;i>=left;i--)
        {
            ans.push_back(matrix[buttom][i]);
        }
        buttom--;
        if(buttom<top) break;
        for(int i=buttom;i>=top;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        // top++; left++; right--; buttom--;
        cout<<top<<" "<<buttom<<"  "<<left<<" "<<right<<endl;
    }
    return ans;
    }
};