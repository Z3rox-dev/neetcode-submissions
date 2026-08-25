class Solution {
public:
    vector<int> visited;
    
    bool dfs(unordered_map<int, vector<int>>& umap, int u){
        visited[u] = 1;

            for(auto v : umap[u]){
                if(visited[v] == 0){
                    bool val = dfs(umap, v);
                    if(val == 0) return false;
                }
                else if(visited[v] == 1){
                    return false;
                }
            }
            visited[u] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector(numCourses, 0);
        unordered_map<int, vector<int>> adjList;
        for(auto& p : prerequisites){
            adjList[p[1]].push_back(p[0]);
        }

        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(dfs(adjList, i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
