class Solution {
public:
#define ll long long
   #define mod 1000000007
    bool bs (vector<int>&nums , ll target , int start)
    {
        int left = start , right = nums.size();
        while(left<right)
        {
            ll mid =(left+right)/2;
            if(nums[mid] == target) return 1;
            if(nums[mid]< target) left=mid+1;
            else right = mid;
        }
        return 0;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>temp;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        map<vector<int>,int>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    ll tt=(target-nums[i]);
                    tt-=nums[j];
                    // if(tt-nums[k]> INT_MIN)
                    tt-=nums[k];
                    // else continue;
                    if(bs(nums , tt ,k+1) )   {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(tt);
                     }
                     if(temp.size()) {
                         mpp[temp]++;
                         temp.clear();
                     }
                }
            }
        }
        cout<<INT_MAX<<endl;
        for(auto &x:mpp) ans.push_back(x.first);
        return ans;
    }
};