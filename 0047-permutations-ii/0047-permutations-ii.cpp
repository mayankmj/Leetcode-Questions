class Solution {
public:
    void ans_finder(set<vector<int>>&ans, vector<int>&temp, vector<int>&vec,vector<int>&nums,int index){
        if(nums.size() == temp.size())
        {
            ans.insert(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!vec[i]){
                temp.push_back(nums[i]);
                vec[i]=1;
                ans_finder(ans,temp,vec,nums,i+1);
                vec[i]=0;
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>temp;
        // freq arrr;
        vector<int>vec(nums.size(),0);
        ans_finder(ans,temp,vec,nums,0);
        vector<vector<int>>vv;
        for(auto &x:ans) vv.push_back(x);
        return vv;
    }
};