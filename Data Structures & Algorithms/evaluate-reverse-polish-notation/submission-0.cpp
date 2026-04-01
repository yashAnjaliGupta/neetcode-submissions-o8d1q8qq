class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> calculationStack;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int first=calculationStack.top();calculationStack.pop();
                int second=calculationStack.top();calculationStack.pop();
                if(tokens[i]=="+"){
                    calculationStack.push(second+first);
                }
                if(tokens[i]=="*"){
                    calculationStack.push(second*first);
                }
                if(tokens[i]=="-"){
                    calculationStack.push(second-first);
                }
                if(tokens[i]=="/"){
                    calculationStack.push(second/first);
                }
            }else{
                calculationStack.push(stoi(tokens[i]));
            }
        }
        return calculationStack.top();
    }
};
