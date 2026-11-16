class Solution {
public:
    int solve(vector<vector<int>> &pairs, int prev, int index, vector<vector<int>> &dp){
        if(index==pairs.size()){return 0;}
        if(dp[index][prev+1]!=-1){return dp[index][prev+1];}

        int pick = 0;
        int notpick = 0;
        
        if(prev==-1 || pairs[prev][1]<pairs[index][0]){
            pick = 1 + solve(pairs, index, index+1, dp);
        }

        notpick = solve(pairs, prev, index+1, dp);

        dp[index][prev+1] =  max(pick, notpick);
        return dp[index][prev+1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        sort(pairs.begin(), pairs.end());
        return solve(pairs, -1, 0, dp);
    }
};