class Solution {
private: 
    int util(int idx,string s){
        if(idx==s.length()){
            return 1;
        }
        if(s[idx]=='0')return 0;
        int res=util(idx+1,s);
        if(idx!=s.length()-1 && ((s[idx]-'0')*10+(s[idx+1]-'0'))<=26){
            res+= util(idx+2,s);
        }
        return res;
    }
public:
    int numDecodings(string s) {
        return util(0,s);
    }
};
