class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1,k=j+1;j<n-1 && k<=n;k++)
            {
                int sum = nums[i] + nums[j];
                if(k ==n || sum<=nums[k])
                {
                    if(k>j+1)
                    ans+=(k-j-1);
                    j++;
                    k--;
                }
                // else k++;
            }
        }
        return ans;
    }
};