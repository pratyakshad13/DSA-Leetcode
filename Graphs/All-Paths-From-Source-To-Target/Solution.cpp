class Solution {
private:
    void getAllPaths(vector<vector<int>>& graph,int node,vector<vector<int>>& ans,vector<int> temp){
        if(node == graph.size() - 1){
            temp.push_back(node);
            ans.push_back(temp);
            return;
        }
        temp.push_back(node);
        for( auto neighbour : graph[node]){
            getAllPaths(graph,neighbour,ans,temp);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        getAllPaths(graph,0,ans,{});
        return ans;
    }
};
