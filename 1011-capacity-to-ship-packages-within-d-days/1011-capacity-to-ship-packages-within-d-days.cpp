class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mx=INT_MIN;
        int n = weights.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            mx=max(weights[i],mx);
            sum+=weights[i];
        }
        int low=mx,high=sum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int d=days,curr_sum=0,maxi=INT_MAX;
            for(int i=0;i<n;i++)
            {
                curr_sum+=weights[i];
                if(curr_sum>mid){
                    d--;
                     maxi = max(maxi,curr_sum-weights[i]);
                    curr_sum = weights[i];
                }
            }
            if(d>0 || maxi<mid) high = mid-1;
            else low=mid+1;
        }
        return low;
    }
};