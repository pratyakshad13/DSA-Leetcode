class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int maxValue = INT_MIN;
        for( auto  element: edges){
            maxValue = max(maxValue,max(element[0],element[1])); // Find the maximum value of the node that could be there.
        }
        
        vector<vector<int>> adj;
        for( int i = 0 ; i <= maxValue ; i++){
            adj.push_back({});
        }

        for( int i = 0 ; i < edges.size() ; i++){
            //create adjlist.
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for( int i = 0 ; i < adj.size() ; i++){
            // for any node, if it contains n-1 nodes in its adjList, the that node is our ans.
            int count = 0; 
            for( auto node : adj[i]){
                count++;
            }
            if( count == maxValue - 1){
                return i;
            }
        }

        return -1;

    }
};
