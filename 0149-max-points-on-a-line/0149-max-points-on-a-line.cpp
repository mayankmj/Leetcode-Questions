class Solution {
public:
    bool check(int i,int j, int k , vector<vector<int>>vec)
    {
        int tt1=vec[i][0]*(vec[j][1]-vec[k][1]);
        int tt2=vec[j][0]*(vec[k][1]-vec[i][1]);
        int tt3=vec[k][0]*(vec[i][1]-vec[j][1]);
        return (tt1+tt2+tt3 == 0);
    }
    int maxPoints(vector<vector<int>>& points) {
        map<double,int>mpp;
        int n=points.size(),ans=0;
        sort(points.begin(),points.end());
        for(int i=0;i<n;i++)
        {
            int count=0; mpp.clear();
            for(int j=i+1;j<n;j++)
            {
                if(points[i][0] == points[j][0]) count++;
                else{
                    double tt1=(points[i][1]-points[j][1]);
                    double tt2=(points[i][0]-points[j][0]);
                mpp[tt1/tt2]++;
                }
            }
             for(auto &x:mpp){
            if(ans<x.second) ans=x.second;
            }
            ans=max(ans,count);
        }
        for(auto &x:mpp){
            if(ans<x.second) ans=x.second;
        }
        return ans+1;
    }
};