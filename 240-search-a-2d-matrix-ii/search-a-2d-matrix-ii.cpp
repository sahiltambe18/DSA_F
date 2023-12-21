class Solution {
    bool bs(vector<int> nums , int target){
        int l = 0 , r = nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid]<target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int rows = matrix.size() ;
     int i = 0 , j = matrix[0].size()-1;
    while(i<rows && j>=0){
        if(matrix[i][j]==target) return true;
        // last element is smaller than t ie not in this row
        else if(matrix[i][j]<target) i++; 
        // last ele of row is large so decrese it
        else j--;
    }
     return false;
    }
};