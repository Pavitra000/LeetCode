class Solution {
public:
    void solve(int i, vector<string> &ans, string &temp, unordered_map<char, vector<char>> hashmap, string digits){
        if(i>=digits.length()){ans.push_back(temp); return;}

        for(auto it: hashmap[digits[i]]){
            temp = temp+it;
            solve(i+1, ans, temp, hashmap, digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> hashmap = {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
        };

        string temp = "";
        vector<string> ans;

        solve(0, ans, temp, hashmap, digits);
        return ans;
    }
};