class Solution {
private:
    void backtrack(int i,string curStr, string& digits,vector<string>& res,vector<string>& digitToChar){
        if(curStr.size()==digits.size()){
            res.push_back(curStr);
            return;
        }
        string chars= digitToChar[digits[i]-'0'];
        for(char c: chars){
            backtrack(i+1,curStr+c,digits,res,digitToChar);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", 
                                  "mno", "qprs", "tuv", "wxyz"};
        if(digits.length()==0)return res;
        backtrack(0,"",digits,res,digitToChar);
        return res;
    }
};
