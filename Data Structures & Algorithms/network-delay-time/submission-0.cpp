class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjL(n+1);
        for(int i=0;i<times.size();i++){
            adjL[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,
            greater<>> minHeap;
        minHeap.push({0,k});
        vector<bool> visited(n+1,false);
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!minHeap.empty()){
            auto curr=minHeap.top();
            minHeap.pop();
            int w=curr.first, n1=curr.second;
            if(visited[n1])continue;
            cout<<w<< " n="<<n1<<endl;
            visited[n1]=true;
            for(int i=0;i<adjL[n1].size();i++){
                int n2=adjL[n1][i].first, w2= adjL[n1][i].second;
                if(dist[n2]>=w+w2){
                    minHeap.push({w+w2,n2});
                    cout<<"push "<<n2<<" , "<<w+w2<<endl;
                    dist[n2]=w+w2;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<dist[i]<<",";
        }
        int res= *max_element(dist.begin()+1,dist.end());
        return res == INT_MAX ? -1 : res;
    }
};
