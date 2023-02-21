class Solution {
public:
    void dfs(int node ,vector<int>&vis , vector<int>adj[],stack<int>&s)
    {
        vis[node]=1;
        // s.push(node);
        for(auto &x:adj[node])
        {
            if(!vis[x]) {cout<<x<<" ";dfs(x,vis,adj,s);}
        }
        s.push(node);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int>s;
        queue<int>q;
        vector<int>ans;
        vector<int>adj[numCourses];
        for(auto &x:prerequisites)
        {
            adj[x[0]].push_back(x[1]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto &y:adj[i]) indegree[y]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) s.push(i);
        }

        while(!s.empty())
        {
            int tt = s.top();
            ans.push_back(s.top());
            s.pop();
            for(auto &x:adj[tt]){
                indegree[x]--;
                if(!indegree[x]) s.push(x);
            }
            
        }
        return (ans.size() == numCourses);
    }
};