//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dfs(int row , int col , vector<vector<int>>&grid, vector<vector<int>>&visited,
    vector<pair<int,int>>&vec,int nrow , int ncol)
    {
        visited[row][col]=1;
        vec.push_back({row-nrow,col-ncol});
        int n = grid.size();
        int m = grid[0].size();
        
        int traverse_row[] = {-1,0,1,0};
        int traverse_col[] = {0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int next_row = row+traverse_row[i];
            int next_col = col+traverse_col[i];
            if(next_row>=0 && next_row<n && next_col>=0 && next_col<m 
            && !visited[next_row][next_col] && grid[next_row][next_col])
            dfs(next_row,next_col,grid,visited,vec,nrow,ncol);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>>ans;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]){
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,visited,vec,i,j);
                    ans.insert(vec);
                }
            }
        }
        return ans.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends