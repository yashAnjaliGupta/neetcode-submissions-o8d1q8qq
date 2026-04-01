class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjL(n);
        for(int i=0;i<edges.size();i++){
            adjL[edges[i][0]].push_back(edges[i][1]);
            adjL[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        int components=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adjL,visited,i);
                components++;
            }
        }
        return components;
    }
    void dfs(vector<vector<int>> &adjL,vector<bool> &visited,int node){
        visited[node]=true;
        for(int i=0;i<adjL[node].size();i++){
            if(!visited[adjL[node][i]]){
                dfs(adjL,visited, adjL[node][i]);
            }
        }
    }
};
