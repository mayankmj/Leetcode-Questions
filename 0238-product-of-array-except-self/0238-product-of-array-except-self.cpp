class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // #define int long long
        int mult1 =1,mult2=1,zero=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]) mult1*=nums[i];
            else zero++;
            mult2*=nums[i];
        }
        vector<int>vec;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]) vec.push_back(mult2/nums[i]);
            else {
                if(zero>1) vec.push_back(0);
                else vec.push_back(mult1);
            }
        }
        return vec;
    }
};