class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ans=-1,n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j] == target) return 1;
            }
        }
        return 0;
    }
};