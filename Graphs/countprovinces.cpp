#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
    vis[node] = 1;

    for (int j = 0; j < isConnected.size(); j++) {
        if (isConnected[node][j] == 1 && !vis[j]) {
            dfs(j, isConnected, vis);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));

    // input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    vector<int> vis(n, 0);
    int count = 0;

    // count provinces
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, isConnected, vis);
        }
    }

    cout << count;

    return 0;
}



//second method
//by creating adjacency list
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));

    // input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    // 🔹 Build adjacency list from matrix
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && isConnected[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> vis(n, 0);
    int count = 0;

    // count provinces
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, adj, vis);
        }
    }

    cout << count;

    return 0;
}