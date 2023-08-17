class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n = nums.size();
        vector<int>visited(n,0);
        queue<int>q; // index;
        q.push(start);
        if(!nums[start]) return 1;
        while(!q.empty())
        {
            int tt = q.front(); q.pop();
            // cout<<tt<<" ";
            int forward = tt + nums[tt];
            int backward = tt - nums[tt];
            // cout<<backward;
            // if(backward == 0 || forward == 0) return 1;
            if(forward<n && forward>=0 && !visited[forward]) q.push(forward);
            if(backward>=0 && backward<n && !visited[backward]) q.push(backward);
            if(forward<n && forward>=0 && !nums[forward]) return 1;
            if(backward>=0 && backward<n && !nums[backward]) return 1;
            visited[tt]=1;
        }
        return 0;
    }
};