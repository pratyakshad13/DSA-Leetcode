class Solution {
private:
    void getTopoSort(vector<vector<int>>& adj,vector<int> & visited,vector<int> & ans,vector<int> & indegree){
        queue<int> q;
        int numCourses = visited.size();

        for(int i = 0 ; i < numCourses ; i++ ){
            if( indegree[i] == 0 ){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for( auto neighbour : adj[node]){
                indegree[neighbour]-- ;
                if( indegree[neighbour] == 0 ){
                    q.push(neighbour);
                }
            }
        }


    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj;

        for( int  i = 0 ; i < numCourses ; i++){
            adj.push_back({});
        }

        for( int i = 0 ; i < prerequisites.size() ; i++ ){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> ans;

        getTopoSort(adj,visited,ans,indegree);
        
        if( ans.size() == numCourses){
            return true;
        }

        return false;
    }
};
