class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> v(m , vector<int>(n , -1));

        queue<pair<pair<int ,int>,int>> q;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    v[i][j] = 1;
                }
            }
        }

        int di[] = {1,-1,0,0};
        int dj[] = {0,0,1,-1};

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int i = node.first.first;
            int j = node.first.second;
            int cost = node.second;

            mat[i][j] = cost;

            for(int x = 0 ; x < 4 ;x++){
                int ni = i + di[x]; 
                int nj = j + dj[x];

                if(ni >=0 && ni < m && nj >=0 && nj< n && v[ni][nj]!=1){
                    v[ni][nj]=1;
                    q.push({{ni,nj},cost+1});
                }
            }
        }

        return mat;

    }
};