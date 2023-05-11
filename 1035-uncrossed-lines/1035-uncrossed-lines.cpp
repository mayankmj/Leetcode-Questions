class Solution {
public:
    int ans_finder(vector<int>&nums1 , vector<int>&nums2,int i,int j,int s1, int s2 , vector<vector<int>>&dp)
    {
        if(i == s1 || j == s2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i] == nums2[j]){
            return dp[i][j]=ans_finder(nums1,nums2,i+1,j+1,s1,s2,dp) +1;
        }

        else
          return dp[i][j]=max(ans_finder(nums1,nums2,i,j+1,s1,s2,dp),ans_finder(nums1,nums2,i+1,j,s1,s2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size() , size2=nums2.size();
        int mx=max(size1,size2);
        vector<vector<int>>dp(mx,vector<int>(mx,-1));
        fill(dp.begin(),dp.end(), vector<int>(mx,-1));
        return ans_finder(nums1,nums2,0,0,size1,size2,dp);
    }
};