class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int n1=flowerbed.size();
        if(n1 ==1) {
            if(n==0) return 1;
            else if(!flowerbed[0] && n<2) return 1;
            else return 0;
        }
        for(int i=0;i<n1;i++)
        {
            if(i == 0){
                if(!flowerbed[i] && !flowerbed[i+1]){
                    n--;
                    flowerbed[i]=1;
                }
            }
            else if(i == n1-1){
                if(!flowerbed[i] && !flowerbed[i-1]) n--;
            }
            else if(!flowerbed[i] && !flowerbed[i-1] && !flowerbed[i+1]){
                n--; flowerbed[i]=1;
                }
        }
        if(n<=0) return 1;
        return 0;
    }
};