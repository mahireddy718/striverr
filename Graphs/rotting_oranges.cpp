#include <bits/stdc++.h>
using namespace std;

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<pair<int,int>,int>>q;
    int vis[n][m]; //instead of else part we can initialize '0's here only
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2; //exception
            }
            else{
                vis[i][j]=0;
            }
        }
    }
    int tm=0;
    int drow[]={-1,1,0,0}; // it is written up down left right we can write anyway
    int dcol[]={0,0,-1,1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            tm=max(t,tm);
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1&&vis[i][j]!=2){
                return -1;
            }
        }
    }
    return tm;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    // input grid
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    int result = minTimeToRot(grid, n, m);

    cout << result;
    
    return 0;
}