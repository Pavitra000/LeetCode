class Solution {
public:
    bool func(vector<int>& bloomDay, int m, int k, int mid){
        int bCount = m;
        int fCount = k;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){fCount--; if(fCount==0){bCount--; fCount=k; if(bCount==0){return 1;}}}
            else{fCount=k;}
        }
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0;
        int high = 0;
        for(int i=0; i<bloomDay.size(); i++){
            high = max(high, bloomDay[i]);
        }
        int mid;

        int ans = INT_MAX;
        while(low<=high){
            mid = (low+high)/2;
            int temp = func(bloomDay, m, k, mid);
            if(temp==1){high = mid-1; ans = min(ans, mid);}
            else{low = mid+1;}
        }
        if(ans==INT_MAX){return -1;}
        else{return ans;}
    }
};