#include<iostream>
#include<vector>
using namespace std;

bool brute(vector<int> &nums){
    for (int i = 0; i < nums.size(); i++)
    {
        for(int j = i ; j < nums.size();j++){
            if (nums[i]==nums[j])
            {
                return true;
            }
            
        }
    }
    return false;
}

bool dup(vector<int> &nums){
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i+1])
        {
            return true;
        }
        
    }
    return false;
}

int main( )
  {

return 0 ;
}