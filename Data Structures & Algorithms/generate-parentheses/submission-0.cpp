class Solution {
private:
void backtrack(int openN,int closedN, int n, vector<string> &ans,string &stack){
    if(openN==closedN && openN==n){
        ans.push_back(stack);
    }
    if(openN<n){
        stack+='(';
        backtrack(openN+1,closedN,n,ans,stack);
        stack.pop_back();
    }
    if(closedN<openN){
        stack+=')';
        backtrack(openN,closedN+1,n,ans,stack);
        stack.pop_back();
    }

}

public:
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        string stack;
        backtrack(0,0,n,ans,stack);
        return ans;

    }
};

