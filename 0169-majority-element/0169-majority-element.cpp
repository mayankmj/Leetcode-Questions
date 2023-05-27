class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=nums[0],count=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]) count++;
            else count=0;
            if(count>=n/2) ans=nums[i];
        }
        return ans;
    }
};