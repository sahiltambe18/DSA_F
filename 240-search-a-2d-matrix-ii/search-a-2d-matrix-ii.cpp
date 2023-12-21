class Solution {
   
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     std::ios::sync_with_stdio(false);
     int rows = matrix.size() ;
     int i = 0 , j = matrix[0].size()-1;
    while(i<rows && j>=0){
        // last ele of row is large so decrese it
        if(matrix[i][j]>target) j--;
        // last element is smaller than t ie not in this row
        else if(matrix[i][j]<target) i++; 
        else return true;
    }
     matrix.clear();
     return false;
    }
};