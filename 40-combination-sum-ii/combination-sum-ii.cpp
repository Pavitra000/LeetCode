class Solution {
public:
    void solve(vector<int> &candidates, int target, int i, int sumi, vector<int> &temp, set<vector<int>> &sett){
        if(sumi == target){sett.insert(temp); return;}
        if(sumi>target || i>=candidates.size()){return;}
        sumi = sumi + candidates[i];
        temp.push_back(candidates[i]);
        solve(candidates, target, i+1, sumi, temp, sett);

        temp.pop_back();
        sumi = sumi-candidates[i];
        int j;
        for(j=i; j<candidates.size()-1; j++){
            if(candidates[j]!=candidates[j+1]){break;}
        }
        solve(candidates, target, j+1, sumi, temp, sett);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        set<vector<int>> sett;

        vector<vector<int>> ans;
        solve(candidates, target, 0, 0, temp, sett);
        for(auto it: sett){
            ans.push_back(it);
        }
        return ans;
    }
};