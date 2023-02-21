class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        queue<int>q;
        for(auto &x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto &x:adj[i]) indegree[x]++;
        }

        for(int i=0;i<numCourses;i++){
            if(!indegree[i]) q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int tt=q.front();
            ans.push_back(tt);
            q.pop();
            for(auto x:adj[tt]) {
                indegree[x]--;
                if(!indegree[x]) q.push(x);
            }
        }
        if(ans.size() ==  numCourses) return ans;
        return {};
    }

};