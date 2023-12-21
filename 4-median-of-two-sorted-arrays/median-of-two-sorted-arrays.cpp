class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int i = 0 , j = 0 , c = 0;
        int e1 = 0 , e2 = 0;
        while((i<nums1.size() || j<nums2.size())&&c<(n/2)+1){
            if(i<nums1.size() && j<nums2.size()){
                if(nums1[i]<nums2[j]){
                    e2 = e1 ;
                    e1 = nums1[i];
                    i++;
                }else{
                    e2 = e1 ;
                    e1 = nums2[j];
                    j++;
                }
                c++;
            }else if(i<nums1.size()){
                e2 = e1 ;
                e1 = nums1[i];
                i++;
                c++;
            }else{
                e2 = e1 ;
                e1 = nums2[j];
                j++;
                c++;
            }
        }

        if(n%2==0){
            return ((double)e1 + (double)e2)/2.0;
        }else{
            return (double)e1; 
        }

    }
};