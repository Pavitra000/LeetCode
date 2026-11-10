class Solution {
public:
    int solve(int row, int col, int m, int n, vector<vector<int>> &dp){
        // if(m==0 && n==0){return 1;}
        // else if(m<0 || n<0){return 0;}

        // return solve(m-1, n)+solve(m,n-1);

        if(row==m-1 && col==n-1){return 1;}
        else if(row>m-1 || col>n-1){return 0;}
        if(dp[row][col]!=-1){return dp[row][col];}
        
        return dp[row][col] = solve(row+1, col, m, n, dp)+solve(row, col+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));

        return solve(0,0,m,n, dp);
    }
};