class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        int maxLen=0;
        for(int i=0;i<n;i++){
            int left,right;
            if(i!=n-1){
                left=i,right=i+1;
                while(left>=0 && right<n && s[left]==s[right]){
                    if(maxLen<=right-left+1){
                        count++;
                    }
                    left--;
                    right++;
                }
            }
            left=i,right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                if(maxLen<=right-left+1){
                    count++;
                }
                left--;
                right++;
            }
            
        }
        // cout<<startIndex<<" "<<maxLen<<endl;
        return count;
    }
};
