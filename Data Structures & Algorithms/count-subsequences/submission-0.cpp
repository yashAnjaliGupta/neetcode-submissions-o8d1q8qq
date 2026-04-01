class Solution {
private:
    int dfs(string s,string t,int i,int j){
        if(j<0)return 1;
        if(i<0)return 0;
        
        //match
        int res=0;
        if(s[i]==t[j])res+=dfs(s,t,i-1,j-1);
        res+=dfs(s,t,i-1,j);

        return res;


    }
public:
    int numDistinct(string s, string t) {
        return dfs(s,t,s.length()-1,t.length()-1);
    }
};
