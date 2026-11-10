class Solution {
public:
    int uniquePaths(int m, int n) {
        long long a = 1;
        long long b = 1;
        long long x = 1;
        long long ans = 1;
        while(1){
            if(x<=m+n-2){ans = ans*x; x++;}
            if(ans%a==0 && a<=m-1){ans = ans/a; a++;}
            if(ans%b==0 && b<=n-1){ans = ans/b; b++;}

            if(x>m+n-2 && a>m-1 && b>n-1){break;}
        }
        return ans;
    }
};