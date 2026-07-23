class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mapp;
        for(int i=0; i<nums.size(); i++){
            if(mapp.find(nums[i])!=mapp.end()){mapp[nums[i]]++;}
            else{mapp[nums[i]]=1;}
        }
        for(auto it = mapp.begin(); it != mapp.end(); ++it){
            if(it->second>nums.size()/3){ans.push_back(it->first);}
        }
        return ans;
    }
};