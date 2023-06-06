class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(),candies.end());
        vector<bool>vec(candies.size(),0);
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies>=mx) vec[i]=1;
        }
        return vec;
    }
};