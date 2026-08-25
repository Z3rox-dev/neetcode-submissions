class Solution {
public:
    vector<int> visit;
    bool dfs (vector<vector<int>>& adjList, int u, int parent, vector<int>& visited){
        visit[u] = 1;

        for(auto& v : adjList[u]){
            if (v == parent) continue;
            if(visit[v] == 1){
                return false;
            }
            if(visit[v] == 0){

                bool b = dfs(adjList, v, u, visited);
                if(b == false){
                    return false;
                }
            }
        }
        visit[u] = 2;
        visited.push_back(u);
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<vector<int>> adjList(n, vector<int>());
        visit = vector<int>(n, 0);
        vector<int> visited;
        for(auto& edge : edges){
            adjList[edge[1]].push_back(edge[0]);
            adjList[edge[0]].push_back(edge[1]);
        }

        if(!dfs(adjList, 0, -1, visited)) return false;
        if(visited.size() != n) return false;
        return true;
    }
};
