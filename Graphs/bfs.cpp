#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
    int v = adj.size();
    vector<int> vis(v, 0);
    vector<int> ans;
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return ans;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    // taking input
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    vector<int> result = bfs(adj);

    // print output
    for (auto it : result) {
        cout << it << " ";
    }

    return 0;
}