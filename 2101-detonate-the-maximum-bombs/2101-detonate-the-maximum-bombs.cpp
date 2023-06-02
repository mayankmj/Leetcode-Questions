class Solution {
public:
    void dfs(int i, vector<int>adj[],vector<int>&vis,int &curr,int ans)
    {
        vis[i]=1;
        curr++;
        for(auto &x:adj[i])
        {
            if(!vis[x]){
                dfs(x,adj,vis,curr,ans);
            }
        }
       
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        #define ll long long
        int n = bombs.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            int x1=bombs[i][0];
            int y1=bombs[i][1];
            ll r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(j == i) continue;
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                ll temp1 = abs(x2-x1);
                ll temp2 = abs(y2-y1);
                if((temp1*temp1 + temp2*temp2)<=r1*r1){
                // cout<<d<<" "<<r1<<endl;
                    adj[i].push_back(j);
                }
            }
        }
        for(auto &x:adj)
        {
            // cout<<x[0]<<"here-> ";
            for(auto &y:x) cout<<y<<" ";
            cout<<endl;
        }
        int curr=1,ans=1;
        vector<int>visited(n+1,0);
        for(int i=0;i<n;i++){

             curr=0;
            vector<int>visited(n+1,0);
                dfs(i,adj,visited,curr,ans);
           
             ans=max(curr,ans);
        }
        return ans;
    }
};