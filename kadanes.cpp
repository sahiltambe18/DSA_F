#include <iostream>
using namespace std;

// kadane's algo for max sub-array

void brute(int arr[], int n)
{
    int maximum = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maximum = max(maximum, sum);
        }
    }
    cout << maximum;
}

void kadane(int arr[] , int n){
    int sum = 0 , maxi = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        sum+= arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        

        if (sum<0)
        {
            sum = 0;
        }
        
    }
    cout<<maxi;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arr2[] = {-2, -3, -1, -2, -3};
    kadane(arr2,5);
    return 0;
}