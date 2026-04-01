class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        vector<vector<int>> tree(n);
        for(int i=0;i<n-1;i++){
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);

        return dfs(tree,0,visited,-1);
    }
    bool dfs(vector<vector<int>> &tree,int node,vector<bool> &visited,int parent){
        if(visited[node])return false;
        visited[node]=true;
        for(int i=0;i<tree[node].size();i++){
            if(tree[node][i]!=parent && !dfs(tree,tree[node][i],visited,node)){
                return false;
            }
        }
        return true;
    }
};
