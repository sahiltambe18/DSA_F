class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int color , int prev){
        if(image[sr][sc]==color || image[sr][sc]!=prev ){
            return ;
        }else if(image[sr][sc]==prev){


        image[sr][sc] = color;

        if(sr>0){
            dfs(image , sr-1 , sc , color , prev);
        }
        if(sr< image.size()-1){
            dfs(image , sr+1 , sc , color , prev);
        }
        if(sc>0){
            dfs(image , sr , sc-1 , color , prev);
        }
        if(sc< image[0].size()-1){
            dfs(image , sr , sc+1 , color , prev);
        }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image , sr , sc , color ,image[sr][sc] );
        return image;
    }
};