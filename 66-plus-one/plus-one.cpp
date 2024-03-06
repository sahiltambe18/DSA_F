class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int c = 1;
        bool flag = 0;
        for(int i = d.size()-1 ; i >=0 ; i--){
            d[i]+=c;
            if(d[i]>9){
                d[i]=0;
                if(i==0){
                    d.insert(d.begin(),1);
                }
            }else if(d[i]<=9){
                c=0;
                break;
            }
        }

        return d;
    }
};