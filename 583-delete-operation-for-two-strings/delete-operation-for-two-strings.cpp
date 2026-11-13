class Solution {
public:
    int solve(string &word1, string &word2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1 < 0 || ind2 < 0){return 0;}
        if(dp[ind1][ind2]!=-1){return dp[ind1][ind2];}

        if(word1[ind1]==word2[ind2]){
            dp[ind1][ind2] = 1+solve(word1, word2, ind1-1, ind2-1, dp);
            return dp[ind1][ind2];    
        }
        else{
            dp[ind1][ind2] =  max(solve(word1, word2, ind1-1, ind2, dp), solve(word1, word2, ind1, ind2-1, dp));
            return dp[ind1][ind2];
        }
    }
    int minDistance(string word1, string word2) {

        int ind1 = word1.length()-1;
        int ind2 = word2.length()-1;
        
        vector<vector<int>> dp(ind1+2, vector<int> (ind2+2, -1));

        int ans = solve(word1, word2, ind1, ind2, dp);
        return ind1+1+ind2+1-2*ans;
    }
};