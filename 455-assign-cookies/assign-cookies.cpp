class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int ans = 0;
        int s_ind = 0;
        int g_ind = 0;
        while(s_ind<s.size() && g_ind<g.size()){
            if(g[g_ind]<=s[s_ind]){ans++; s_ind++; g_ind++;}
            else{s_ind++;}
        }
        return ans;
    }
};