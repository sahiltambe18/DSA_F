class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i =  0 , j = people.size()-1;
        int count = 0 ;
        while(i<=j){
            int p = 0;
            int capacity = limit;
            while(i<=j && p<2 && people[j]<=capacity){
                capacity-=people[j];
                j--;
                p++;
            }

            while(i<=j&& p<2 && people[i]<=capacity){
                capacity-=people[i];
                i++;
                p++;
            }
            count++;
        }
        return count;
    }
};