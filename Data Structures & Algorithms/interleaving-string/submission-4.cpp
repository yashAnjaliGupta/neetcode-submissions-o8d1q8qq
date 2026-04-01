class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i=0,j=0;
        for(int k=0;k<s3.length();k++){
            if(j<s2.length() && s2[j]==s3[k]){
                j++;
            }else if(i<s1.length()&&s1[i]==s3[k]){
                i++;
            }
            else{
                cout<<s3[k]<<k;
                return false;
            }
        }
        if(i==s1.length()&& j==s2.length())
        return true;
        return false;
    }
};
