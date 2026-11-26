class Solution {
public:
    void dfs(vector<vector<int>> &adjList, int i, vector<int> &visited){
        if(visited[i]==0){
            visited[i]=1;

            for(auto next: adjList[i]){
                if(visited[next]==0){
                    dfs(adjList, next, visited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(n);
        int provinces = 0;

        for(int i=0; i<visited.size(); i++){
            if(visited[i]==0){
                dfs(adjList, i, visited);
                provinces++;
            }
        }
        return provinces;
    }
};