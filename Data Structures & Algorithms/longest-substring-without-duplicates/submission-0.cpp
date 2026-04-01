class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,maxLength=0;
        unordered_map<char,int> mp;
        for(int right=0;right<s.length();right++){
            mp[s[right]]++;
            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
            }
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};
