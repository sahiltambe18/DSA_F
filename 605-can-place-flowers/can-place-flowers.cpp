class Solution {
public:
   // int marked[20005];
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       // int ans = 0;
        for(int i = 0; i < flowerbed.size(); ++i){
            if(flowerbed[i] == 1){
                if(i-1 > -1) flowerbed[i-1] = 2;
                if(i+1 < flowerbed.size()) flowerbed[i+1] =2;
                flowerbed[i] = 1;
            }
        }
        
        for(int i = 0; i < flowerbed.size(); ++i){
            if(!flowerbed[i]){
                // ++ans;
                n--;
                flowerbed[i] = 1;
                if(i-1 > -1) flowerbed[i-1] = 1;
                if(i+1 < flowerbed.size()) flowerbed[i+1] = 1;
            }
        }

        return n<=0;
        
    }
};