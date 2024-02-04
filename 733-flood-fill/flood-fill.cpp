class Solution {
    void flood(vector<vector<int>>& image , int x , int y , int color , int prev){
        if(x>=image.size() || y>=image[0].size() || color==image[x][y] ){
            return;
        }else if(prev==image[x][y]){
            image[x][y] = color;
            flood(image,x+1,y,color,prev);
            flood(image,x-1,y,color,prev);
            flood(image,x,y+1,color,prev);
            flood(image,x,y-1,color,prev);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        flood( image , sr,sc , color , image[sr][sc]);
        return image;
    }
};