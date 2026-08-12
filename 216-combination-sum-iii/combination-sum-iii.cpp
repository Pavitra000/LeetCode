class Solution {
public:
    void solve(int i, int n, int sumi, int k, vector<int> &nums,vector<vector<int>> &ans, vector<int> &temp){
        if(sumi==n && temp.size()==k){ans.push_back(temp);return;}
        if(i>=nums.size()){return;}

        sumi = sumi+nums[i];
        temp.push_back(nums[i]);
        solve(i+1, n, sumi, k, nums, ans, temp);

        sumi = sumi-nums[i];
        temp.pop_back();
        solve(i+1, n, sumi, k, nums, ans, temp);

        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, n, 0, k, nums, ans, temp);
        return ans;
    }
};