class Solution {
public:
    int minimumPartition(string s, int k) {
        long long int ans=0,n=s.size(),curr=0;
        for(int i=0;i<n;i++)
        {
            curr = curr*10 + s[i]-'0';
            if(curr>k)
            {
                ans++;
                curr = s[i]-'0';
            }
            if(curr>k) return -1;
        }
        if(curr<=k) ans++;
        return ans;
    }
};