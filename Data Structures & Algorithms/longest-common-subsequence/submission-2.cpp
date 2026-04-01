class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.length()<text2.length()){
            swap(text1,text2);
        }
        int n=text1.length(),m=text2.length();
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            int prev=0;
            for(int j=1;j<=m;j++){
                int temp=dp[j];
                if(text1[i-1]==text2[j-1]){
                    dp[j]=prev+1;
                }else{
                    dp[j]=max(dp[j],dp[j-1]);
                }
                prev=temp;
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<dp[i][j]<<", ";
        //     }
        //     cout<<endl;
        // }
        return dp[m];
    }
};
