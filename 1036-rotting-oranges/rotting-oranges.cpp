class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(m,vector<int> (n,0));

        vector<int> drow = {1,0,-1,0};
        vector<int> dcol = {0,-1,0,1};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){q.push({{i,j},0}); visited[i][j]=2;}
            }
        }
        int time = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();
            for(int k=0; k<4; k++){
                int nr = r+drow[k];
                int nc = c+dcol[k];

                if(nr>=0 && nc>=0 && nr<m && nc<n && visited[nr][nc]==0 && grid[nr][nc]==1){
                    q.push({{nr,nc},t+1});
                    visited[nr][nc]=2;
                }
            }
            time = t;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && visited[i][j]==0){return -1;}
            }
        }
        return time;
    }
};