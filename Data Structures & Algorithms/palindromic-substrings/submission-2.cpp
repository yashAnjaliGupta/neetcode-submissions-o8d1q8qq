class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int res=0;
        for(int gap=0;gap<n;gap++){
            for(int i=0;i<n-gap;i++){
                int j=i+gap;
                if(j==i){
                    cout<<i<<endl;
                    res++;
                    dp[i][j]=true;
                }
                else if(s[i]==s[j]&&j==i+1){
                    dp[i][j]=true;
                    res++;
                }
                else if(s[i]==s[j]&&dp[i+1][j-1]){
                    dp[i][j]=true;
                    res++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
        return res;
        
    }
};
