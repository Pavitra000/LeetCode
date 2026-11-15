class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){return 0;}

        int left = 1;
        int right = nums[0];
        int step = 1;
        int maxi = 0;
        while(left<nums.size()-1 && right<nums.size()-1){
            for(int i=left; i<=right; i++){
                maxi = max(maxi, i+nums[i]);
            }
            left = right+1;
            right = maxi;
            maxi = 0;
            step++;
        }
        return step;
    }
};