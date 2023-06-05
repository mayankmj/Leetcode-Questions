class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n == 2) return 1;
        for(int i=2;i<n;i++)
        {
            int x1 = coordinates[i][0],y1 = coordinates[i][1];
            int x2 = coordinates[i-1][0],y2 = coordinates[i-1][1];
            int x3 = coordinates[i-2][0],y3 = coordinates[i-2][1];

            int area = y1*(x2-x3) + y2*(x3-x1) + y3*(x1-x2);
            if(area) return 0;
        }
        return 1;
    }
};