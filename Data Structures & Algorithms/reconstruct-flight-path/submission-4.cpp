class Solution {
private:
    void dfs(string src,unordered_map<string,deque<string>>& adj,vector<string>& res){
        while(!adj[src].empty()){
            string dst=adj[src].back();
            adj[src].pop_back();
            dfs(dst,adj,res);
        }
        res.push_back(src);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [src, dests] : adj) {
            sort(dests.rbegin(), dests.rend());
        }
        
        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
