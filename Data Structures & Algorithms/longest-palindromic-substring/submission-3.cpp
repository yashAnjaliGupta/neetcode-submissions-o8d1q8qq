class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=1,startIndex=0;
        for(int i=0;i<n-1;i++){
            int left,right;
            left=i,right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                if(maxLen<right-left+1){
                    maxLen=right-left+1;
                    startIndex=left;
                    cout<<i<<" "<<startIndex<<" "<<maxLen<<endl;
                }
                left--;
                right++;
            }
            left=i,right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                if(maxLen<right-left+1){
                    maxLen=right-left+1;
                    startIndex=left;
                    cout<<i<<" "<<startIndex<<" "<<maxLen<<endl;
                }
                left--;
                right++;
            }
            
        }
        cout<<startIndex<<" "<<maxLen<<endl;
        return s.substr(startIndex,maxLen);
    }
};
