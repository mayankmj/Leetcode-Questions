//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        // int N=edges.size();
        vector<int>adj[N];
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(N,0);
        vector<int>ans(N,1e9);
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty())
        {
            int node = q.front().first;
            int dis = q.front().second;
            ans[node]=min(ans[node],dis);
            visited[node]=1;
            q.pop();
            for(auto &child:adj[node])
            {
                if(!visited[child])q.push({child,dis+1});
                else ans[child] = min(ans[child],dis+1);
            }
        }
        for(int i=0;i<N;i++)
        {
            if(ans[i] == 1e9) ans[i]=-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends