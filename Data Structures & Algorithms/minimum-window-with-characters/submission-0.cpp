class Solution {
private:
    bool mapComp(vector <int> tHashMap,vector <int> window){
        for(int i=0;i<256;i++){
            if(tHashMap[i]>window[i]){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        vector <int> tHashMap(256,0);
        vector <int> window(256,0);
        for(int i=0;i<t.size();i++){
            cout<<int(t[i])<<endl;
            tHashMap[t[i]]++;
        }
        int left=0;
        int minIndex=-1,minSize=s.size()+1;
        
        for(int right=0;right<s.size();right++){
            window[s[right]]++;
            cout<<left<<" "<<right<<endl;
            while(mapComp(tHashMap,window)){
                minSize=right-left+1;
                minIndex=left;
                window[s[left]]--;
                left++;
            }
        }
        if(minIndex==-1)return "";
        return s.substr(minIndex,minSize);

    }
};
