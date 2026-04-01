class Solution {
    bool Util(const string s,unordered_set<string>& strHash,int idx,unordered_map<int,bool> & memo){
        // cout<<"------"<<s.substr(idx)<<endl;
        if(memo.find(idx)!=memo.end())return memo[idx];
        if(strHash.find(s.substr(idx))!=strHash.end())return true;
        if(idx==s.size())return memo[idx]=true;
        for(int i=idx;i<s.length();i++){
            // cout<<'l'<<s.substr(idx,i-idx)<<endl;
            if(strHash.find(s.substr(idx,i-idx+1))!=strHash.end()){
                // cout<<s.substr(idx,i)<<","<<s.substr(i)<<endl;
                bool flag= Util(s,strHash,i+1,memo);
                if(flag)return memo[idx]=true;
            }
        }
        return memo[idx]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> strHash(wordDict.begin(),wordDict.end());
        unordered_map<int,bool> memo;
        return Util(s,strHash,0,memo);
    }
};
