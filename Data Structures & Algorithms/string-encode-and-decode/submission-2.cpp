class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString="";
        for(int i=0;i<strs.size();i++){
            int stringLength=strs[i].length();
            encodedString+=to_string(stringLength);
            encodedString+='#';
            encodedString+=strs[i];
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        string length_string="";
        int sLength=0;
        string temp;
        int i=0;
        cout<<s<<endl;
        while(i<s.length()){
            while(i<s.length()&&s[i]!='#'){
                length_string+=s[i];
                i++;
            }
            i++;
            cout<<length_string<<endl;
            sLength=stoi(length_string);
            temp=s.substr(i,sLength);
            decodedStrings.push_back(temp);
            i+=sLength;
            length_string ="";
        }
        return decodedStrings;
    }
};
