class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int>vec(3,0);
        set<vector<int>> set;
        sort(nums.begin(),nums.end());
        int left = 1;
        int right = nums.size()-1;

        //left is for the left side se travesal
        //right is for right side se
        for(int i=0; i<nums.size()-2; i++){
            left = i + 1;
            right = nums.size()-1;
            while(left<right){
            if(nums[left]+nums[right]>(-1*nums[i])){right--;}
            else if(nums[left]+nums[right]<((-1)*nums[i])){left++;}
            //abb if koi triplet match ho jata h toh usko set me add kr lete h
            else{vec[0] = nums[i];vec[1] = nums[left];vec[2] = nums[right]; set.insert(vec);left++; right--;}
            }
        }
        for(auto it: set){
            ans.push_back(it);
        }
        return ans;
    }
};