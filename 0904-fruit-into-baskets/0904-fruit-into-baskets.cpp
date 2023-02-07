class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans =0,start=0,n=fruits.size();
        map<int,int>mpp;
        for(int i=0;i<fruits.size();i++)
        {
            mpp[fruits[i]]++;
            if(mpp.size() == 2) ans=max(i-start+1,ans);
            if(mpp.size()>2){
                if(mpp[fruits[start]] ==1) mpp.erase(fruits[start]);
                else mpp[fruits[start]]--;
                start++;
            }
            cout<<mpp.size()<<" "; 
        }
        // cout<<mpp.size()<<" "<<ans<<endl;
        if(mpp.size()<=2) ans=max(ans,n-start);
        return ans;
    }
};