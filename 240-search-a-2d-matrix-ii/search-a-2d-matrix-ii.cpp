class Solution {
   
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