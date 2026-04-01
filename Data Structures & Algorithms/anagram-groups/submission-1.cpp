class Solution {
public:
    vector<int> getFrequencyMap(string str){
        vector<int> frequencyMap(26,0);
        for(int i=0;i<str.length();i++){
            frequencyMap[str[i]-'a']++;
        }
        return frequencyMap;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> hashMap;
        for(int i=0;i<strs.size();i++){
            vector<int> frequencyMap=getFrequencyMap(strs[i]);
            hashMap[frequencyMap].push_back(strs[i]);
        }
        vector<vector<string>> output;
        for(auto itr:hashMap){
            output.push_back(itr.second);
        }
        return output;
    }
};
