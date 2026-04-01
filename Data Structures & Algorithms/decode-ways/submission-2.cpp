class Solution {
private: 
    int util(int idx,string s,vector<int>&dp){
        if(idx==s.length()){
            return dp[idx]=1;
        }
        if(dp[idx]!=-1)return dp[idx];
        if(s[idx]=='0')return dp[idx]=0;
        int res=util(idx+1,s,dp);
        if(idx!=s.length()-1 && ((s[idx]-'0')*10+(s[idx+1]-'0'))<=26){
            res+= util(idx+2,s,dp);
        }
        return dp[idx]=res;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        int dp=0,dp2=0,dp1=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp=0;
            }
            else{
                dp=dp1;
                if(i+1<n && ((s[i]-'0')*10+(s[i+1]-'0'))<=26){
                    dp+=dp2;
                }
            }
            dp2=dp1;
            dp1=dp;
            dp=0;
        }
        return dp1;
    }
};
