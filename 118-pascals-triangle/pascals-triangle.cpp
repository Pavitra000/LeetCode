class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> top;
        vector<int> bottom;
        vector<vector<int>>ans;
        if(numRows==0){return ans;}
        top.push_back(1);
        ans.push_back(top);
        if(numRows==1){return ans;}
        top.push_back(1);
        ans.push_back(top);
        if(numRows==2){return ans;}
        for(int i=1; i<=numRows-2; i++){
            bottom.push_back(1);
            for(int j=0; j<=top.size()-2; j++){
                bottom.push_back(top[j]+top[j+1]);
            }
            bottom.push_back(1);
            ans.push_back(bottom);
            top = bottom;
            bottom.clear();
            bottom.shrink_to_fit();
        }
        return ans;
    }
};