class Solution {
public:
    int solve(int n, vector<int> &arr){
        if(n==1 || n==0){return n;}
        if(arr[n]!=-1){return arr[n];}
        arr[n] = solve(n-1, arr) + solve(n-2, arr);
        return arr[n];
    }
    int fib(int n) {
        vector<int> arr(n+1,-1);
        int ans = solve(n, arr);
        return ans;
    }
};