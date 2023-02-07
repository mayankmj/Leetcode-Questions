class Solution {
public:
    bool check(map<char,int>mpp , int k)
    {
        if(mpp.size()<3) return 0;
        for(auto x:mpp){
            if(x.second<k) return 0;
        }
        return 1;
    }
    int takeCharacters(string s, int k) {
        if(!k) return 0;
        map<char,int>mpp;
        for(auto &x:s) mpp[x]++;
        // checking for -1;
        for(auto &x:mpp){
            if(x.second<k) return -1;
            // x.second = min(k,x.second);
        }
        if(mpp.size()<3) return -1;
        int j = 0 , n=s.size(),ans=n ,window=0;
        for(int i=0;i<n;i++)
        {
            mpp[s[i]]--;
            window++;

            while(mpp[s[i]]<k){
                mpp[s[j++]]++;
                window--;
            }

            ans = min(ans,n-window);
        }
        return ans;
    
        return ans;
    }
};