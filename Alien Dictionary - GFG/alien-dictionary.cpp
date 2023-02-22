//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        // int n = dict.size();
        int n=N;
        vector<int>adj[K];
        for(int i=0;i<n-1;i++)
        {
            string first=dict[i];
            string second=dict[i+1];
            // cout<<first;
            int fs=dict[i].size(),ss=dict[i+1].size(),x=0,y=0;
            while(x<fs && y<ss)
            {
                if(first[x]!=second[y]) {
                    adj[first[x]-97].push_back(second[y]-97);
                    break;
                }
                x++;y++;
            }
        }
        // bfs topo sort
        vector<int>inDegree(K,0);
        for(int i=0;i<K;i++)
        {
            for(auto &x:adj[i]) inDegree[x]++;
        }
        
        queue<int>q;
        for(int i=0;i<K;i++){
            if(inDegree[i] == 0) q.push(i);
        }
        string ans="";
        while(!q.empty())
        {
            int tt = q.front();q.pop();
            ans = ans+char(tt+'a');
            for(auto &x:adj[tt])
            {
                inDegree[x]--;
                if(inDegree[x] == 0) q.push(x);
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends