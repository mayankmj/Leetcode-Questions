class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>mst;
        vector<int>vec;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            mst.insert(nums[i]);
            if(mst.size() == k)
            {
                int tt = *prev(mst.end());
                vec.push_back(tt);
                mst.erase(mst.find(nums[j++]));
            }
        }
        return vec;
    }
};