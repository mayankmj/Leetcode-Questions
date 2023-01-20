class Solution {
public:
    vector<vector<int>>ans;
    void ans_finder(vector<int>&nums,int index ,vector<int>&vec,set<vector<int>>&s)
    {
         if(vec.size()>=2) s.insert(vec);
        if(index == nums.size()) return;

        for(int i=index;i<nums.size();i++)
        {
             if(vec.empty() || nums[i]>=vec.back() ) {
                vec.push_back(nums[i]);
            ans_finder(nums,i+1,vec,s);        /// 4 6 7 7
                vec.pop_back();
            //  ans_finder(nums,i+1,vec,s);
             }
            //  vec.empty();
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>vec;
        set<vector<int>>s;
        ans_finder(nums,0,vec,s);
        return vector<vector<int>> (s.begin(),s.end());
    }
};