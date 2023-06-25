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

void kadane(int arr[],int n){
    int sum = 0 , maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if (sum>maxi)
        {
            maxi = sum;
        }

        if (sum<0)
        {
            sum = 0;
        }
        
        
    }
    cout << maxi;
    
}

void kadane_start_end(int arr[], int n)
{
    int sum = 0, maxi = INT16_MIN;
    int start = -1, endp = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            if (i == 0)
            {
                start = 0;
            }
            endp = i;
        }

        if (sum < 0)
        {
            sum = 0;

            start = i + 1;
        }
    }
    cout << maxi << "  " << start << " " << endp;
}

int main()
{
    int arr[] = {4, -3, 4, -1, -2, 1, 5, -3};
    int arr2[] = {-2, -3, -1, -2, -3};
    kadane(arr, 8);
    return 0;
}