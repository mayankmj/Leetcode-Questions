class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n>=maxPts+k) return 1.00000;
        vector<double>dp(n+1,0.0);
        dp[0]=1;
        double maxSum=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=maxSum/(double)maxPts;
            if(i<k) maxSum+=dp[i];
            if(i-maxPts>=0){
                maxSum-=dp[i-maxPts];
            }
        }
        double sum=0;
        for(int i=n;i>=k;i--){
            sum+=dp[i];
        }
        return sum;
    }
};