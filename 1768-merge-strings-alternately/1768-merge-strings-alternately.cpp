class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        string ans="";
        for(int i=0;i<n1 && i<n2;i++)
        {
            ans+=word1[i];
            ans+=word2[i];
        }
        if(n1>n2){
            for(int i=n2;i<n1;i++) ans+=word1[i];
        }
        if(n2>n1){
            for(int i=n1;i<n2;i++) ans+=word2[i];
        }
        return ans;
    }
};