class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mpp;
        for(auto &x:s1) mpp[x]++;
        int k=s1.size();
        int count = mpp.size();
        int p=0;
        for(int i=0;i<s2.size();i++)
        {
            if(mpp.find(s2[i])!=mpp.end()) {
                mpp[s2[i]]--;
                if(!mpp[s2[i]]) count--;
            }

            if(i - p+1 == k)
            {
                if(!count) return 1;
                if(mpp.find(s2[p]) !=mpp.end()) {
                mpp[s2[p]]++;
                if(mpp[s2[p]] == 1) count++;
                }
                p++;
            }
            cout<<count<<" ";
        }
        return 0;
    }
};