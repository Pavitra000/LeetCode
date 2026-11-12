class Solution {
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp){
        if(amount==0){return 0;}
        else if(amount<0){return INT_MAX;}
        if(dp[amount]!=-1){return dp[amount];}

        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int temp = solve(coins, amount-coins[i], dp);
            int ans;
            if(temp==INT_MAX){ans = INT_MAX;}
            else{ans = 1+temp;}

            mini = min(mini, ans);
        }
        dp[amount] = mini;

        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);

        int mini = solve(coins, amount, dp);
        if(mini==INT_MAX){return -1;}
        return mini;
    }
};