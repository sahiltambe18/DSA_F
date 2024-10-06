class Solution {
    vector<string> stringSplit(string s){
        vector<string>  v;
        string word;
        stringstream ss(s);
        while(ss>>word){
            v.push_back(word);
        }
        return v;
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        if(l1==l2){
            return s1==s2;  
        }
        vector<string> v1,v2;
        v1 = stringSplit(s1);
        v2 = stringSplit(s2);
        if(v1.size() > v2.size()){
            vector<string> t = v1;
            v1 = v2;
            v2 = t;
        }

        l1 = v1.size();
        l2 = v2.size();

        int i = 0;
        for(i ; i < l1 ;i++){
            if(v1[i]!=v2[i]) break;
        }

        if(i>=l1) return 1;

        int r1 = l1-1 , r2 = l2-1;
        while(r1>=0 && r2>=0){
            if(v1[r1]!=v2[r2]) break;
            r1--;
            r2--;
        }
        if(r1<i) return 1;
        return 0;
        
    }
};