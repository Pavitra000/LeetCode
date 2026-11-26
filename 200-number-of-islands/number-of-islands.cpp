class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int> (m,0));
        queue<pair<int,int>> q;

        vector<int> drow = {0,1,0,-1};
        vector<int> dcol = {1,0,-1,0};
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    //starting point of loop bfs
                    q.push({i,j});
                    visited[i][j]=1;

                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        for(int ind=0; ind<4; ind++){
                            
                            int nrow = row+drow[ind];
                            int ncol = col+dcol[ind];
                            
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                                visited[nrow][ncol]=1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};