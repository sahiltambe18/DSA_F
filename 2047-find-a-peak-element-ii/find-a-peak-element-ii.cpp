class Solution {
public:
   
   int maxi(vector<vector<int>>& mat ,int mid){
       int mx = INT_MIN;
       int ind = 0;
       for(int i = 0 ; i < mat.size() ; i++){
           if(mat[i][mid]>mx){
               ind = i;
               mx = mat[i][mid];
           }
       }
       return ind;
   }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size() ; 
        int col = mat[0].size() ;
        
        int l = 0 , r = col-1;

        while(l<=r){
            int mid = l + (r-l)/2;
            int ind = maxi(mat,mid);
            
            int left = mid-1>=0? mat[ind][mid-1]:-1;
            int right = mid+1<col?mat[ind][mid+1]:-1;

            if(mat[ind][mid]>left && mat[ind][mid]>right) return {ind , mid};
            else if(mat[ind][mid]<left) r = mid-1;
            else l = mid+1;
        } 
        return {};
    }
};