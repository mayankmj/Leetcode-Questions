class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        // will apply dijkastra
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>ans(n+1,INT_MAX);
        priority_queue<pair<int,int>>q;
        // dist, node;
        ans[k]=0;
        q.push({0,k});
        while(!q.empty())
        {
            int node = q.top().second,dist = q.top().first;
            q.pop();
            // cout<<adj[node].size()<<endl;
            for(auto &child:adj[node])
            {
                int d = child.second, nod = child.first;
                // cout<<nod<<" "<<d<<endl;
                if(ans[nod]>dist+d)
                {
                    q.push({ans[node]+d,nod});
                    ans[nod]=ans[node]+d;
                }
            }
        }
        int mx=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            // cout<<ans[i]<<" ";
            if(ans[i] == INT_MAX) return -1;
            mx=max(mx,ans[i]);
        }
        return mx;
    }
};