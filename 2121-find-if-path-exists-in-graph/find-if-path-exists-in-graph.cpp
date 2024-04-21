class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }

        unordered_map<int, vector<int>> g;
        for (auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(source);
        vis[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : g[node]) {
                if (!vis[neighbor]) {
                    if (neighbor == destination) {
                        return true;
                    }
                    vis[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};
