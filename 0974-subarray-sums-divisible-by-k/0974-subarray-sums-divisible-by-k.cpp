class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans = 0,sum=0;
        map<int,int>mpp;
        for(auto &x:nums)
        {
            sum+=x;
            sum=sum%k;
            if(sum<0){
                int temp = k+sum;
                mpp[temp%k]++;
            }
            else
            mpp[sum%k]++;
            
        }
        for(auto &x:mpp) cout<<x.first<<" "<<x.second<<endl;
        for(auto &x:mpp)
        {
           ans+=x.second*(x.second-1)/2;
           if(x.first ==0) ans+=x.second;
        }
        return ans;

    }
};