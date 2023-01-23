class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>hash(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            hash[trust[i][1]]++;
            hash[trust[i][0]]=-5;
        }
        for(int i=1;i<=n;i++){
            if(hash[i] == n-1) return i;
        }
        return -1;
    }
};