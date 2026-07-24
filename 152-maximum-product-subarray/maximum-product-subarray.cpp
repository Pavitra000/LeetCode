class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int temp = 1;
        int maxipre = INT_MIN;
        int maxisuf = INT_MIN;
        bool flag1 = false;
        bool flag0 = false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){temp=1; flag0=true; continue;}
            if(nums[i]>0){flag1 = true;}
            temp = temp*nums[i];
            maxipre = max(maxipre,temp);
        }
        temp = 1;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]==0){temp=1; continue;}
            temp = temp*nums[i];
            maxisuf = max(maxisuf,temp);
        }
        if(flag0==true && max(maxipre,maxisuf)<0){return 0;}
        return max(maxipre,maxisuf);
    }
};