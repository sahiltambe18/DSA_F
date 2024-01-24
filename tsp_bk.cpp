#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> ans;

// int graph[10][10] = {
//     {0, 10, 15, 20},
//     {10, 0, 35, 25},
//     {15, 35, 0, 30},
//     {20, 25, 30, 0}
// };

vector<vector<int>> graph;

int minCost = INT_MAX;
int n;

// to check if all vertices are visited
bool allVisited(const vector<bool> &v)
{
    for (auto i : v)
    {
        if (!i)
        {
            return false;
        }
    }
    return true;
}

void tsp(vector<bool> &v, int cost, int c, vector<int> &path)
{
    if (allVisited(v))
    {
        if (cost + graph[c][0] < minCost)
        {
            minCost = cost + graph[c][0];
            ans = path;
            ans.push_back(0);
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!v[i] && i != c)
        {
            v[i] = true;
            path.push_back(i);
            tsp(v, cost + graph[c][i], i, path);
            path.pop_back();
            v[i] = false;
        }
    }
}

int main()
{
    cout << "Enter no of vertices\n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> v(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int e;
                cout << "enter cost of " << i << " to " << j << endl;
                cin >> e;
                v[j] = e;
            }
        }
        graph.push_back(v);
    }

    vector<bool> v(n, false);

    // Start from vertex 0
    v[0] = true;

    vector<int> initialPath;
    initialPath.push_back(0);
    tsp(v, 0, 0, initialPath);

    cout << "shortest path: ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Min Cost: " << minCost;

    return 0;
}
