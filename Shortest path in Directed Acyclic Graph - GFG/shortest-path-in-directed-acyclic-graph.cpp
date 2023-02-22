//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(vector<int>&vis,stack<int>&st,vector<pair<int,int>>adj[],int node)
     {
         vis[node]=1;
         for(auto &x:adj[node])
         {
             if(!vis[x.first]) dfs(vis,st,adj,x.first);
         }
         st.push(node);
         
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>vis(N,0);
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!vis[i]) dfs(vis,st,adj,i);
        }
        vector<int>distance(N,1e9);
        distance[0]=0;
        while(!st.empty())
        {
            int tt=st.top();st.pop();
            for(auto &x:adj[tt])
            {
                int q=x.first,w=x.second;
                distance[q]=min(distance[q],distance[tt]+w);
            }
        }
        for(int i=0;i<N;i++)
        {
            if(distance[i] == 1e9) distance[i]=-1;
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends