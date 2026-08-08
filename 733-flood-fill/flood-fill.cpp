class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited(m, vector<int> (n,0));

        vector<int> drow = {1,0,-1,0};
        vector<int> dcol = {0,1,0,-1};

        int currentColor = image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        visited[sr][sc]=1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int nr = r+drow[k];
                int nc = c+dcol[k];
                
                if(nr>=0 && nc>=0 && nr<m && nc<n && visited[nr][nc]==0 && image[nr][nc]==currentColor){
                    image[nr][nc]=color;
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};