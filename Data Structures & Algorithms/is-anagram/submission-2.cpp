class Solution {
public:
    bool isAnagram(string s, string t) {
        int sFrequencyMap[26]={0},tFrequencyMap[26]={0};
        for(int i=0;i<s.length();i++){
            sFrequencyMap[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            tFrequencyMap[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(sFrequencyMap[i]!=tFrequencyMap[i])return false;
        }
        return true;
    }
};
