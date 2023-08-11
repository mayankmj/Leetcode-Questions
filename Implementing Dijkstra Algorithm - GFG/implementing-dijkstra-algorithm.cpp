//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> graph[], int S)
    {
        // Code here
        vector<pair<int,int>>adj[V];
        // adj => {node,distance}
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back({graph[i][j][1],graph[i][j][0]});
            }
        }
        priority_queue<pair<int,int>>pq;
        pq.push({0,S});
        
        vector<int>ans(V,INT_MAX);
        ans[S]=0;
        while(!pq.empty())
        {
            int dist = pq.top().first,node = pq.top().second;
            pq.pop();
            for(auto &child:adj[node])
            {
                int curr = dist + child.first;
                if(ans[child.second]>curr)
                {
                    pq.push({curr,child.second});
                    ans[child.second] = curr;
                }
            }
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends