class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>>ans;
        if(nums.size()<4){return ans;}
        sort(nums.begin(),nums.end());
        set<vector<int>>set;
        vector<int>vec(4,0);
        int low;
        int high;
        for(int i=0; i<nums.size()-3; i++){
            for(int j=i+1; j<nums.size()-2; j++){
                low = j+1;
                high = nums.size()-1;
                while(low<high){
                long long temp = (long long)nums[i]+(long long)nums[j]+(long long)nums[low]+(long long)nums[high];
                if(temp>target){high--;}
                else if(temp<target){low++;}
                else{
                    vec[0]=nums[i];
                    vec[1]=nums[j];
                    vec[2]=nums[low];
                    vec[3]=nums[high];
                    set.insert(vec);
                    low++;
                    high--;
                }}
            }
        }
        for(auto &it: set){
            ans.push_back(it);
        }
        return ans;
    }
};