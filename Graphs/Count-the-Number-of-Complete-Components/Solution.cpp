class Solution {
private:
    void dfs(int node,vector<int> adj[],vector<int> & visited,int &numberOfNodes,int &numberOfEdges){
        visited[node] = 1;
        numberOfNodes++;


        for( auto currNode : adj[node]){
            numberOfEdges++;
            if(!visited[currNode]){
                
                dfs(currNode,adj,visited,numberOfNodes,numberOfEdges);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for( int i = 0 ; i  < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        int count = 0;

        for(int i = 0 ; i < n ; i++){
            int numberOfNodes = 0 ;
            int numberOfEdges = 0;
            if(!visited[i]){
                dfs(i,adj,visited,numberOfNodes,numberOfEdges);
                // cout<<"number of Edgdes : "<<numberOfEdges<<endl;;
                if((numberOfEdges/2) == ((numberOfNodes*(numberOfNodes - 1))/2)){ // numberOfEdges/2 as inside function bidirectional edges are counted.
                    count++;
                }
            }
        }
        return count;
    }
};
