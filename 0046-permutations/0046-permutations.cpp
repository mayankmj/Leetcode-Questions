class Solution {
public:
    void ans_finder(vector<int>&temp,vector<vector<int>>&ans,vector<int>&freq,int index,vector<int>&nums)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return ;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                ans_finder(temp,ans,freq,i+1,nums);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>freq(nums.size(),0);
        vector<int>temp;
        ans_finder(temp,ans,freq,0,nums);
        return ans;
    }
};