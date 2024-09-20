class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1 ; i< n ; i++){
            for(int j = 0 ; j< n;j++){
                int mini = matrix[i-1][j];
                if(j>0 && matrix[i-1][j-1] < mini ) mini = matrix[i-1][j-1];
                if(j+1<n && matrix[i-1][j+1] < mini) mini = matrix[i-1][j+1];
                matrix[i][j]+= mini;
            }
        }
        int mini = matrix[n-1][0];
        for(auto &i : matrix[n-1]){
            if(i<mini) mini = i;
        }
        return mini;
    }
};