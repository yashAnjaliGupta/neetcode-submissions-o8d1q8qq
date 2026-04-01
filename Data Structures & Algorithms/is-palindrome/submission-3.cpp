class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.length()-1;
        while(left<right){
            while(!((s[left]>='a'&&s[left]<='z')||(s[left]>='A'&&s[left]<='Z')||(s[left]>='0'&&s[left]<='9'))){
                left++;
            }
            while(!((s[right]>='a'&&s[right]<='z')||(s[right]>='A'&&s[right]<='Z')||(s[left]>='0'&&s[left]<='9'))){
                right--;
            }
            if(left<right){
                char leftChar = s[left], rightChar =s [right];
                if(leftChar >='A'&& leftChar<='Z'){
                    leftChar=leftChar-'A'+'a';
                }
                if(rightChar>='A'&& rightChar<='Z'){
                    rightChar=rightChar-'A'+'a';
                }
                if(leftChar!=rightChar)return false;
                left++;
                right--;
            }
        }
        return true;
    }
};
