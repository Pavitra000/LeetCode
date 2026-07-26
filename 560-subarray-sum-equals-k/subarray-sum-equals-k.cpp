class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;
        int sumi = 0;
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            sumi = sumi+nums[i];
            if(prefix.find(sumi-k) != prefix.end()){ans = ans+prefix[sumi-k];}
            if(prefix.find(sumi) != prefix.end()){prefix[sumi]++;}
            else if(prefix.find(sumi) == prefix.end()){prefix[sumi] = 1;}
            if(sumi == k){ans++;continue;}
        }
        return ans;
    }
};