class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hashMap;
        for(int i=0;i<nums.size();i++){
            hashMap[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> ans;
        for(auto itr=hashMap.begin();itr!=hashMap.end();itr++){
            buckets[itr->second].push_back(itr->first);
        }
        for(int i=0;i<nums.size();i++){
            cout<<i<<" --> ";
            for(int j=0;j<buckets[i].size();j++){
                cout<<buckets[i][j]<<", ";
            }
            cout<<endl;
        }
        int kCount=0;
        for(int i=nums.size();i>=0;i--){
            if(!buckets[i].empty()){
                for(int j=0;j<buckets[i].size();j++){
                    if(kCount>=k){
                        return ans;
                    }
                    ans.push_back(buckets[i][j]);
                    kCount++;
                }
            }
            if(kCount>=k){
                return ans;
            }
        }
        return ans;
    }
};
