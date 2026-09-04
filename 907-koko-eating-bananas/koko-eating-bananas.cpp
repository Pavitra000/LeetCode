class Solution {
public:
    long long func(vector<int> &piles, int rate){
        long long ans = 0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]%rate==0){ans = ans+piles[i]/rate;}
            else{ans = 1 + ans + piles[i]/rate;}
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            high = max(high, piles[i]);
        }
        int mid;
        int ans = INT_MAX;
        while(low<=high){
            mid = (low+high)/2;
            if(func(piles, mid)>h){low = mid+1;}
            else if(func(piles, mid)<=h){ans = min(ans, mid); high = mid-1;}
        }
        return ans;
    }
};