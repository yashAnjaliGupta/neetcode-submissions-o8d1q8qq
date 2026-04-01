class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,maxFreq=0,res=0;
        unordered_map<char,int> hashMp;
        for(int right=0;right<s.size();right++){
            hashMp[s[right]]++;
            maxFreq=max(maxFreq,hashMp[s[right]]);

            while((right-left+1)-maxFreq>k){
                hashMp[s[left]]--;
                left++;
            }
            res=max(res,(right-left+1));
        }
        return res;
    }
};
