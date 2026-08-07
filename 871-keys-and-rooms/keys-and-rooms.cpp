class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        queue<int> q;
        vector<int> visited(n,0);

        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int roomNo = q.front();
            q.pop();
            for(auto key : rooms[roomNo]){
                if(visited[key]==0){
                    visited[key]=1;
                    q.push(key);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(visited[i]==0){return false;}
        }
        return true;
    }
};