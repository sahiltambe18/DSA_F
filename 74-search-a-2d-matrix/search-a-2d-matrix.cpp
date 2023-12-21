class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0  , r = matrix.size()-1;
        int i = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]<target){
                l = mid+1;
                i = mid;
            }else{
                r = mid-1;
            }
        }
        l = 0;
        r = matrix[i].size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[i][mid]==target){
                return true;
            }else if(matrix[i][mid]<target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return false;
    }
};