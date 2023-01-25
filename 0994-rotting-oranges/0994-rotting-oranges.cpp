class Solution {
public:
#define ll long long
    int ans=0;
    void ans_finder(vector<vector<int>>&grid , vector<pair<int,int>>&rotten)
    {
        vector<pair<int,int>>temp;
        for(int i=0;i<rotten.size();i++)
        {
            int x = rotten[i].first , y = rotten[i].second , max_j=grid[x].size()-1;
            int max_i=grid.size()-1;
            int opt1=grid[x][min(y+1,max_j)];
            int opt2=grid[max(0,x-1)][y];
            int opt3=grid[min(x+1,max_i)][y];
            int opt4=grid[x][max(0,y-1)];
            if(opt1 == 1){
                temp.push_back({x,min(y+1,max_j)});
                grid[x][min(y+1,max_j)]=2;
            }
            if(opt2 == 1) {temp.push_back({max(0,x-1),y}); grid[max(0,x-1)][y]=2;}
            if(opt3 == 1) {temp.push_back({min(x+1,max_i),y}); grid[min(x+1,max_i)][y]=2;}
            if(opt4 == 1) {temp.push_back({x,max(0,y-1)}); grid[x][max(0,y-1)]=2;}
        }

        if(temp.size()!= 0){
            rotten=temp;temp.clear();
            ans++;
            ans_finder(grid,rotten);
        } 
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>>rotten;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] == 2) rotten.push_back(make_pair(i,j));
            }
        }
        ans_finder(grid,rotten);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;   
    }

};