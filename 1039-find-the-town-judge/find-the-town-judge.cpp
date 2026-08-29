class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustsSomeone(n + 1, 0);
        vector<int> trustedBySomeone(n + 1, 0);

        if(n==1){return 1;}
        for(auto it: trust){
            trustsSomeone[it[0]]++;
            trustedBySomeone[it[1]]++;
        }

        for(int i=0; i<=n; i++){
            if(trustsSomeone[i]==0 && trustedBySomeone[i]==n-1){return i;}
        }

        return -1;
    }
};