class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>mpp;
        for(auto &x:p) mpp[x]++;
        int count = mpp.size() , k = p.size() ,  start=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            if(mpp.find(s[i])!= mpp.end()) {
                mpp[s[i]]--;
                if(!mpp[s[i]]) count--;
            }

            if(i - start+ 1 == k){
                if(!count) ans.push_back(start);
                if(mpp.find(s[start])!=mpp.end()){
                    mpp[s[start]]++;
                    if(mpp[s[start]] == 1) count++;
                }
                start++;
            }
        }
        return ans;
    }
};