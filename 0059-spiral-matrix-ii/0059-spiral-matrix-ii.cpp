class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int left=0,right=n-1,top=0,buttom=n-1,count=1;
        while(1)
        {
            if(left>right) break;
            for(int i=left;i<=right;i++)
            {
                ans[top][i]=count;
                count++;
            }
            top++;
            if(top>buttom)  break;
            for(int i=top;i<=buttom;i++)
            {
                ans[i][right]=count;
                count++;
            }
            right--;
            if(right<left) break;
            for(int i=right;i>=left;i--)
            {
                ans[buttom][i]=count;
                count++;
            }
            buttom--;
            if(buttom<top) break;
            for(int i=buttom;i>=top;i--)
            {
                ans[i][left]=count;
                count++;
            }
            left++;
        }
        return ans;
    }
};