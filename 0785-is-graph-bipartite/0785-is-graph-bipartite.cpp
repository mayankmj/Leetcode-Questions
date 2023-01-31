class Solution {
public:
    bool isCheck(vector<vector<int>>&graph , vector<int>&visited , int start)
    {
        bool ans = 1;
	    queue<int>q;
        q.push(start);
	    while(!q.empty())
	    {
	        int temp = q.front();
	        q.pop();
	        int tt=visited[temp]+1;
	        for(auto &x:graph[temp])
	        {
	            if(visited[x] == -1){
	                q.push(x);
	                visited[x]=tt%2;
	            }
	            else if(visited[x] == visited[temp] && x!=temp) {cout<<temp<<" "<<x<<endl;return 0;}
	        }
	    }
	    return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
         vector<int> visited(n+1,-1);
	    // visited[0]=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i] == -1){
            if(!isCheck(graph,visited,i)) return false;
            }
        }
        return true;
    }
};