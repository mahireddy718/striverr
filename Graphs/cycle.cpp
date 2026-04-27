class Solution {
  public:
  bool dfs(int start,int p,vector<vector<int>>& adjls,vector<int>&vis){
      vis[start]=1;
      for(auto it:adjls[start]){
          if(!vis[it]){
              if(dfs(it,start,adjls,vis)){
                  return true;
              }
          }
          else if(it!=p)return true;
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adjls(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjls[u].push_back(v);
            adjls[v].push_back(u);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,adjls,vis)){
                    return true;
                }
            }
        }
        return false; 
    }
};