class Solution {
public:
    int reverse(int x) {
        long long int ans=0;
        int temp=abs(x);
        while(temp){
            ans=ans*10+temp%10;
            temp=temp/10;
        }
        if(ans>INT_MAX)return 0;
        if(x<0)ans*=-1;
        return ans;
    }
};
