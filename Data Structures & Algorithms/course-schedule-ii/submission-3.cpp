class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> order;
        vector<bool> visited(numCourses,false);
        vector<bool> path(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                if(DFS(graph,visited,path,i,order))
                    return {};
            
        }
        return order;
    }
    bool DFS(vector<vector<int>> graph,vector<bool> &visited,vector<bool> &path,int node,vector<int>& order){
        if(path[node]){
            return true;
        }
        visited[node]=true;
        path[node]=true;
        for(int i=0;i<graph[node].size();i++){
            if(!visited[graph[node][i]] && DFS(graph,visited,path,graph[node][i],order)){
                return true;
            }
            if(path[graph[node][i]])return true;
        }
        path[node]=false;
        order.push_back(node);
        return false;
    }
};
