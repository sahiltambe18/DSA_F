
class Solution {
public:
    int compareVersion(string v1,  string v2) {
        int n1 = v1.length(), n2 = v2.length();
        int i1 = 0, i2 = 0; 
        
        while (i1 < n1 || i2 < n2) {
            int val1 = 0, val2 = 0;
            
            while(i1 < n1 && v1[i1]!='.') {
                val1 = val1*10+(v1[i1]-'0');
                i1++;
            }
            
            while(i2 < n2 && v2[i2]!='.') {
                val2 = val2*10+(v2[i2]-'0');
                i2++;
            }
        
            i1++;
            i2++;
            if (val1 < val2) return -1;
            if (val1 > val2) return 1;
        }
        

        return 0;
    }
};
