
class Solution {
public:
    int compareVersion(string v1,  string v2) {
        int n1 = v1.length(), n2 = v2.length();
        int i1 = 0, i2 = 0; 
        
        while (i1 < n1 || i2 < n2) {
            int val1 = 0, val2 = 0;
            
            if (i1 < n1) {
                auto dot1 = v1.find('.', i1);
                if (dot1 ==  string::npos) dot1 = n1; 
                val1 =  stoi(v1.substr(i1, dot1 - i1));
                i1 = dot1 + 1;
            }
            
            
            if (i2 < n2) {
                auto dot2 = v2.find('.', i2);
                if (dot2 ==  string::npos) dot2 = n2; 
                val2 =  stoi(v2.substr(i2, dot2 - i2));
                i2 = dot2 + 1;
            }
            
            
            if (val1 < val2) return -1;
            if (val1 > val2) return 1;
        }
        

        return 0;
    }
};
