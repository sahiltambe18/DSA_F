class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans =0;

        for(int i = 0; i <n ; i++){
            int xora = 0;
            for(int j = i+1 ;j<n ;j++){
                xora^=arr[j-1];
                int xorb = 0;
                for(int k = j ; k<n ;k++){
                    xorb^=arr[k];
                    if(xora==xorb) ans++;
                }
            }
        }
        return ans;
    }
};