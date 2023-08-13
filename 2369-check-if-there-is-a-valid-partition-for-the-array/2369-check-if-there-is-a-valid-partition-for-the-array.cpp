class Solution {
public:
    bool solve(vector<int>&nums,int index,vector<int>&dp)
    {
        if(index == nums.size()) return 1;
        vector<int>temp;
        bool f=false;
        if(dp[index]!=-1) return dp[index];
        for(int i=index;i<index+3 && i<nums.size(); i++)
        {
            temp.push_back(nums[i]);
            if(temp.size()>=2)
            {
                if(temp[0] == temp[1] && temp.size() == 2)
                {
                    f = f | solve(nums,i+1,dp);
                    // dp[i]=f;
                }
                if(!f && temp.size() == 3)
                {
                    // sort(temp.begin(),temp.end());
                    if((temp[2]-1 == temp[1] && temp[1]-1 == temp[0]) || (temp[0] == temp[1] && temp[1] == temp[2]))
                    {
                        f = f | solve(nums,i+1,dp);
                        // dp[i]=f;
                    }
                }
            }
        }
        dp[index]=f;
        return f;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,dp);
    }
};