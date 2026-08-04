class Solution {
private:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adjList) {
        visited[node] = 1;
        for(auto it: adjList[node]){
            if(!visited[it]){
                visited[it]=1;
                dfs(it, visited, adjList);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodeCount = isConnected.size();
        vector<vector<int>> adjList(nodeCount);
        for(int i=0; i<nodeCount; i++){
            for(int j=0; j<nodeCount; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        //we have the adj list now, now lets do the travesal in each province
        //i will make a visited list now
        vector<int> visited(nodeCount,0);
        int provinceCount = 0;
        for(int node=0; node<visited.size(); node++){
            if(visited[node]==0){visited[node]=1; provinceCount++; dfs(node, visited, adjList);}
        }
        // we have the count number now as provinceCount
        return provinceCount;
    }
};