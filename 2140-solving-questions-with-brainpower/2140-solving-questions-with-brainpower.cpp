class Solution {
public:
    long long ans_finder(vector<vector<int>>&q , int i , vector<long long >&dp)
    {
        if(i>=q.size()) return 0;
        long long opt1=0,opt2=0;
        if(dp[i]!=-1) return dp[i];
        else{
        opt1=q[i][0]+ans_finder(q,i+q[i][1]+1,dp);
        opt2=ans_finder(q,i+1,dp);
        return dp[i] = max({opt1,opt2});
         }
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long>dp(n,-1);
        return(ans_finder(q,0,dp));
        // for
        // for(auto &x:dp) cout<<x<<" ";
        // return 1;
    }
};