class Solution {
public:
    int solve(int n, vector<int> &arr){
        if(n==1 || n==0){return n;}
        if(arr[n]!=-1){return arr[n];}
        arr[n-1] = solve(n-1, arr);
        arr[n-2] = solve(n-2, arr);
        return arr[n-1]+arr[n-2];
    }
    int fib(int n) {
        vector<int> arr(n+1,-1);
        int ans = solve(n, arr);
        return ans;
    }
};