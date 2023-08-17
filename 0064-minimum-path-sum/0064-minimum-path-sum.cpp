class Solution {
public:
    int ans_finder(vector<vector<int>>&grid, int i , int j,vector<vector<int>>&dp)
    {
        int n= grid.size(),m=grid[0].size();
       if(i == n-1 && j == m-1) return dp[i][j] = grid[i][j];
       if(dp[i][j]!=-1) return dp[i][j];
       int opt1=INT_MAX,opt2=INT_MAX;

        if(i+1<n) opt1 = grid[i][j] + ans_finder(grid,i+1,j,dp);
        if(j+1<m) opt2 = grid[i][j] + ans_finder(grid,i,j+1,dp);
        // cout<<min(opt1,opt2)<<endl;
        return dp[i][j] = min(opt1,opt2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int sum=0,n = grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       int me =  ans_finder(grid,0,0,dp);
        return dp[0][0];
    }
};

// 1 2
// 1 1