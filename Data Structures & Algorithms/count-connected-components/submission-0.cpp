class Solution {
public:
    int count = 0;
    void dfs(vector<vector<int>>& adjList, int node, vector<int>& visited){
        visited[node] = 1;

        for(auto currentNode : adjList[node]){
            if(visited[currentNode] == 0){
                dfs(adjList, currentNode, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n, vector<int>());
        vector<int> visited(n);

        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                count++;
                dfs(adjList, i, visited);
            }
        }

        return count;
    }
};
