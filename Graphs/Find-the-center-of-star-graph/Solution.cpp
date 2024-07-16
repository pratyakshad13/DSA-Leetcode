class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int maxValue = INT_MIN;
        for( auto  element: edges){
            maxValue = max(maxValue,max(element[0],element[1]));
        }
        
        vector<vector<int>> adj;
        for( int i = 0 ; i <= maxValue ; i++){
            adj.push_back({});
        }

        for( int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for( int i = 0 ; i < adj.size() ; i++){
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
