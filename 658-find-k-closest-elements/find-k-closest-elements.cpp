class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int  n = arr.size();
        int l = 0 , r = n-1;

        while(r-l>=k){
            if(abs(x-arr[l])>abs(x-arr[r])){
                l++;
            }else{
                r--;
            }
        }
        for(int i = l ; i <= r ; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};