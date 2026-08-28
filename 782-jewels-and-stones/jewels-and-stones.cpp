class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int> sett;
        for(int i=0; i<jewels.length(); i++){
            sett.insert(jewels[i]);
        }
        int ans = 0;
        for(int i=0; i<stones.length(); i++){
            if(sett.find(stones[i])!=sett.end()){ans++;}
        }
        return ans;
    }
};