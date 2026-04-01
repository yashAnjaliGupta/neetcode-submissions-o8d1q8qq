class Solution {
private:
    void stringAdd(string& ans,string num){
        int c=0;
        for(int i=0;i<num.size();i++){
            if(i<ans.size()){
                int digit=(ans[i]-'0'+num[i]-'0'+c);
                ans[i]= (digit%10 + '0');
                c=digit/10;
            }else{
                int digit=(num[i]-'0'+c);
                ans+= (digit%10 + '0');
                c=digit/10;
            }
        }
        int idx=num.size();
        while(c>0){
            if(idx<ans.size()){
                int digit=(ans[idx]-'0'+c);
                ans[idx]= (digit%10 + '0');
                c=digit/10;
            }else{
                int digit=c;
                ans+= (digit%10 + '0');
                c=digit/10;
            }
        }
    }
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans="";
        cout<<num1<<" "<<num2<<endl;
        for(int i=0;i<num1.length();i++){
            string temp="";
            int m1=num1[i]-'0';
            int c=0;
            for(int k=0;k<i;k++)temp+='0';
            for(int j=0;j<num2.length();j++){
                int m2=num2[j]-'0';
                int digit=m1*m2+c;
                temp+=(digit%10 + '0');
                c=digit/10;
            }
            while(c>0){
                temp+=(c%10 +'0');
                c/=10;
            }
            cout<<temp<<endl;
            stringAdd(ans,temp);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
