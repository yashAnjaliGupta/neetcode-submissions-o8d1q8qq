class Solution {
public:
    bool isPalindrome(string s) {
        string p="";
        string r="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c>='A'&&c<='Z')c=c-'A'+'a';
            if((c>='a'&&c<='z')||(c>='0'&&c<='9')){
                p=p+c;
                r=c+r;
            }
        }
        return p==r;
    }
};
