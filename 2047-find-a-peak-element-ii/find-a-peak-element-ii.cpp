class Solution {
public:
   int f(vector<vector<int>>& mat , int n, int m , int mid){
       int maxi = INT_MIN ; 
       int ind = 0 ; 
       for(int i=0 ; i<n ; i++){
           if(mat[i][mid]>maxi){
               maxi = mat[i][mid] ; 
               ind = i ; 
           }
       }
       return ind ; 
   }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() ; 
        int m = mat[0].size() ; 
        int low = 0 , high = m-1 ; 
        while(low<=high){
            int mid = (low+high)/2 ; 
            int maxi = f(mat , n , m , mid) ; 
            int left = mid-1>=0 ? mat[maxi][mid-1]:-1 ; 
            int right = mid+1<m ? mat[maxi][mid+1]:-1 ; 
            if(mat[maxi][mid]>left and mat[maxi][mid]>right) return {maxi , mid} ; 
            else if(left>mat[maxi][mid]) high = mid-1 ; 
            else low = mid+1 ; 
        }
        return {-1 , -1} ; 
    }
};