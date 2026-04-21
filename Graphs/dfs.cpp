#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) {
    vis[node] = 1;
    ans.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, ans);
        }
    }
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

    vector<int> vis(V, 0);
    vector<int> ans;

    // start DFS from node 0
    dfs(0, adj, vis, ans);

    // print result
    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}