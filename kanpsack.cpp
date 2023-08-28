#include <iostream>
using namespace std;

struct Object
{
    float pt;
    float wt;
    float ratio;
    void rt()
    {
        ratio = pt / wt;
    }
};

void bubblesort(Object s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (s[j].pt > s[j + 1].pt)
            {
                Object temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void sortByRatio(Object s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (s[j].ratio > s[j + 1].ratio)
            {
                Object temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

float profit(Object s[], int n, float tot)
{
    float temp = tot;
    float profit = 0;
    for (int i = n - 1; i >= 0 && temp > 0; i--)
    {
        if (temp >= s[i].wt)
        {
            temp -= s[i].wt;
            profit += s[i].pt;
        }
        else if (temp < s[i].wt)
        {
            profit += (temp * s[i].ratio);
            return profit;
        }
    }
    return profit;
}



int main()
{
    int num;
    float tot;
    cout << "enter number of objects\n";
    cin >> num;
    cout << "enter total wt\n";
    cin >> tot;
    Object obj[20];

    for (int i = 0; i < num; i++)
    {
        cout << "enter pr of obj\n";
        cin >> obj[i].pt;
        cout << "enter wt of obj\n";
        cin >> obj[i].wt;
        obj[i].rt();
    }
    //bubblesort(obj, num);
    sortByRatio(obj , num);

    for (int i = 0; i < num; i++)
    {
        cout << i << " " << obj[i].pt << " " << obj[i].wt << " " << obj[i].ratio << endl;
    }
    cout << endl;
    float pr = profit(obj, num, tot);
    cout << "profit is " << pr << endl;

    return 0;
}

/*
enter number of objects
7
enter total wt
16
enter pr of obj
10
enter wt of obj
2
enter pr of obj
15
enter wt of obj
4
enter pr of obj
12
enter wt of obj
5
enter pr of obj
4
enter wt of obj
4
enter pr of obj
6
enter wt of obj
2
enter pr of obj
16
enter wt of obj
3
enter pr of obj
8
enter wt of obj
3
0 4 4 1
1 12 5 2.4
2 8 3 2.66667
3 6 2 3
4 15 4 3.75
5 10 2 5
6 16 3 5.33333

profit is 59.8
PS C:\Users\Admin\Desktop\TA67> 
*/