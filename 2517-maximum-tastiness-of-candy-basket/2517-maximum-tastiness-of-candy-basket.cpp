class Solution {
public:
    bool binary_s(int mid ,vector<int>&price,int k)
    {
        int n = price.size(),comp = price[0],counter=1;
        for(int i=1;i<n;i++)
        {
            if(price[i]-comp>=mid){
                comp = price[i];
                counter++;
            }
        }
        return (counter>=k);
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n =price.size();
        int mx = price[n-1], mn = price[0];
        int hi = mx-mn, lo = 0,ans=0;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            bool check = binary_s(mid,price,k);
            if(check) ans = mid ,lo = mid+1;
            else hi = mid-1;
        }
        return hi;
    }
};