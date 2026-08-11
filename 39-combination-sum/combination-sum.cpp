class Solution {
public:
    void solve(vector<int> &candidates, int target, int i, int sumi, vector<int> &tempAns, vector<vector<int>> &ans){
        if(i>=candidates.size() || sumi > target){return;}
        if(sumi == target){ans.push_back(tempAns); sumi = 0; return;}

        sumi = sumi+candidates[i];
        tempAns.push_back(candidates[i]);
        solve(candidates, target, i, sumi, tempAns, ans);
        sumi = sumi-candidates[i];
        tempAns.pop_back();
        solve(candidates, target, i+1, sumi, tempAns, ans);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tempAns;
        solve(candidates, target, 0, 0, tempAns, ans);

        return ans;
    }
};