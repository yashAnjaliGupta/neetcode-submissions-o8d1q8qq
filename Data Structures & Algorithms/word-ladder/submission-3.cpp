class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListHash(wordList.begin(),wordList.end()),visited;
        if(wordListHash.find(endWord)==wordListHash.end())return 0;
        cout<<"case 1\n";
        visited.insert(beginWord);
        queue<string> bfsQ;
        bfsQ.push(beginWord);
        int level=1;
        while(!bfsQ.empty()){
            // cout<<bfsQ.size()<<endl;
            int qSize=bfsQ.size();
            for(int lElem=0;lElem<qSize;lElem++){
                string word=bfsQ.front();bfsQ.pop();
                for(int i=0;i<word.length();i++){
                    string newWord=word;
                    for(int cha=0;cha<26;cha++){
                        newWord[i]='a'+cha;
                        if(newWord!=word && wordListHash.find(newWord)!=wordListHash.end()&& visited.find(newWord)==visited.end()){
                            bfsQ.push(newWord);
                            visited.insert(newWord);
                            cout<<newWord<<i<<" "<<lElem<<", ";
                            if(newWord==endWord){
                                return level+1;
                            }
                        }

                    }
                }
            }
            cout<<endl;
            level++;
            cout<<level<<endl;
        }
        return 0;

    }
};
