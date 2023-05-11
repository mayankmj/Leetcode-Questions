class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        if(!nums.size()) return 0;
        int temp=1,mx=1,comp=-1,flag=0;
        for(auto &x:mpp)
        {
            if(!flag){
                comp=x.first;
                flag++;
                continue;
            }
            if(comp+1 == x.first){
                comp++;
                temp++;
            }
            else{
                comp=x.first;
                temp=1;
            }
            cout<<temp<<" ";
            mx=max(mx,temp);
        }
        return mx;
    }
};