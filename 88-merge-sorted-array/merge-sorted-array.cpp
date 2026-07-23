class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int fin = m+n-1;
        m--; n--;
        while(m!=-1 && n!=-1){
            if(nums1[m]>=nums2[n]){nums1[fin] = nums1[m]; m--; fin--;}
            else{nums1[fin] = nums2[n]; n--; fin--;}
        }
        if(m==-1){while(n!=-1){nums1[fin]=nums2[n]; n--; fin--;}}
        else if(n==-1){while(m!=-1){nums1[fin]=nums1[m]; m--; fin--;}}
    }
};