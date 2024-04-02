class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int  l = flowerbed.size(); 

        if(l<=1){
            if(flowerbed[0]) return n<=0;
            else return (n-1)<=0;
        }

        if(l>=2 && !(flowerbed[0] || flowerbed[1])){
            flowerbed[0] = 1;
            n--;
        }
        if(l>=2 && !(flowerbed[l-2] || flowerbed[l-1])){
            flowerbed[l-1] = 1;
            n--;
        }

        for(int i = 1 ; i < l-1 ; i++ ){
            if(flowerbed[i]==0){
                if(!(flowerbed[i-1] || flowerbed[i+1])){
                    flowerbed[i] = 1;
                    n--;
                    i++;
                }   
            }
            if(n==0){
                return true;
            }
        }
        
        return n<=0;
    }
};