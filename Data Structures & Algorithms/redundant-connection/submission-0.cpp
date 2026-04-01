class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adjL(n+1);
        int indegree[n+1]={0};
        for(int i=0;i<n;i++){
            adjL[edges[i][0]].push_back(edges[i][1]);
            adjL[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        queue <int> bfsQ;
        for(int i=1;i<=n;i++){
            if(indegree[i]==1)bfsQ.push(i);
        }
        while(!bfsQ.empty()){
            int node=bfsQ.front();bfsQ.pop();
            indegree[node]--;
            for(int i=0;i<adjL[node].size();i++){
                indegree[adjL[node][i]]--;
                if(indegree[adjL[node][i]]==1)bfsQ.push(adjL[node][i]);
            }
        }
        for(int i=edges.size()-1;i>=0;i--){
            if(indegree[edges[i][0]]==2 && indegree[edges[i][1]]){
                return edges[i];
            }
        }
        return {};
        
    }
};
