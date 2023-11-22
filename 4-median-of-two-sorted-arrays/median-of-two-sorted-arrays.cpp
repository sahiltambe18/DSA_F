class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;

        int l1 = nums1.size();
        int l2 = nums2.size();

        // if(l1>l2){
        //     return findMedianSortedArrays(nums2,nums1);
        // }

        int t1 = 0 , t2 = 0;
        while(t1<l1  && t2<l2){
            if(nums1[t1]<=nums2[t2]){
                arr.push_back(nums1[t1]);
                t1++;
            }else{
                arr.push_back(nums2[t2]);
                t2++;
            }
        }
        
            while(t1<l1){
                arr.push_back(nums1[t1]);
                t1++;
            }
        
            while(t2<l2){
                arr.push_back(nums2[t2]);
                t2++;
            }
        

        if(arr.size()%2==0){
            int mid = arr.size()/2;
            return (arr[mid]+arr[mid-1])/2.0;
        }else{
            int mid = arr.size()/2;
            return arr[mid];
        }

    }
};