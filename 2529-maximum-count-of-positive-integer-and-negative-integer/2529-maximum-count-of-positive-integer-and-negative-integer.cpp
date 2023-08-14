class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size(),zero=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0) zero++;
        }
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid = high + (low-high)/2;
            if(high>0 && nums[mid]>=0 && nums[mid-1]<0) {
                int ans  = max(mid,n-mid-zero); 
                return ans;}
            if(nums[mid]<0) low=mid+1;
            else high=mid-1;
        }
        return n-zero;
    }
};