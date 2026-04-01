class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1FreqMap(26,0);
        vector<int> s2FreqMap(26,0);
        for(int i=0;i<s1.size();i++){
            s1FreqMap[s1[i]-'a']++;
            s2FreqMap[s2[i]-'a']++;
        }
        
        int left=0;
        for(int i=s1.size();i<s2.size();i++){
            if(s1FreqMap==s2FreqMap){
                return true;
            }
            s2FreqMap[s2[i]-'a']++;
            s2FreqMap[s2[left]-'a']--;
            left++;
        }
        if(s1FreqMap==s2FreqMap)return true;
        return false;
        
    }
};
