//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>>adj[])
    {
        // mst container N-1 edges only
        // we take smaller edges only and visit every vertex
        // int ans=0;
        
        vector<int>visited(V,0);
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            // auto parent = pq.top();
            int parent = pq.top().second,dist=pq.top().first;
            pq.pop();
            
        if (visited[parent] == 1) {
            continue;  // Skip if this node has already been visited
        }
        // cout<<parent<<" ";

            for(auto &child:adj[parent])
            {
                int node = child[0],d = child[1];
                if(visited[node] == 0) {
                    pq.push({d,node});
                    // cout<<node<<" ";
                }
            }
            visited[parent] =1;
            ans+=dist;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends