class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi_ind = 0;
        for(int i=0; i<n; i++){
            if(i>maxi_ind){return false;}

            maxi_ind = max(maxi_ind, i+nums[i]);
        }
        return true;
    }
};