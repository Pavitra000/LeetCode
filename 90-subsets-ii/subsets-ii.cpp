class Solution {
public:
    void solve(vector<int> &nums, set<vector<int>> &ans, vector<int> &temp, int i){
        if(i>=nums.size()){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, ans, temp, i+1);

        temp.pop_back();
        solve(nums, ans, temp, i+1);

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> temp;
        vector<vector<int>> ansset;

        solve(nums, ans, temp, 0);
        
        for(auto it: ans){
            ansset.push_back(it);
        }

        return ansset;
    }
};