class Solution {
public:
    int solve(vector<int> &nums, int index, vector<int> &dp){
        if(index>=nums.size()){return 0;}
        if(dp[index]!=-1){return dp[index];}

        int temp1 = solve(nums, index+2, dp)+nums[index];
        int temp2 = solve(nums, index+1, dp);

        int ans = max(temp1, temp2);
        dp[index] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        
        int ans = solve(nums, 0, dp);
        return ans;
    }
};