#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> ans;

int graph[10][10] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int minCost = INT_MAX;
int n;

bool all(const vector<bool>& v) {
    for (auto i : v) {
        if (!i) {
            return false;
        }
    }
    return true;
}

void tsp(vector<bool>& v, int cost, int c, vector<int>& path) {
    if (all(v)) {
        if (cost < minCost) {
            minCost = cost;
            ans = path;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!v[i] && i!=c) {
            v[i] = true;
            path.push_back(i);
            tsp(v, cost + graph[c][i], i, path);
            path.pop_back();
            v[i] = false;
        }
    }
}

int main() {
    cout << "Enter no of vertices\n";
    cin >> n;
    
    // Initialize the visited vector with false values
    vector<bool> v(n, false);

    // Start from vertex 0
    v[0] = true;

    // Create an explicit vector<int> and pass it to the function
    vector<int> initialPath;
    initialPath.push_back(0);
    tsp(v, 0, 0, initialPath);

    cout << "Min path: ";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout<<endl;
    cout << "Min path: "<<minCost;

    return 0;
}
