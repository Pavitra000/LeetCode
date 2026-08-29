class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mapp;

        for(int i=0; i<s.length(); i++){
            if(mapp.find(s[i])==mapp.end()){mapp.insert({s[i],1});}
            else{mapp[s[i]]++;}
        }
        for(int i=0; i<s.length(); i++){
            if(mapp[s[i]]==1){return i;}
        }
        return -1;
    }
};