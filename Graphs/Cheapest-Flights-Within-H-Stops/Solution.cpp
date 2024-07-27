class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj;

        for( int i =  0 ; i < n; i++){
            adj.push_back({});
        }

        for( int i = 0 ; i < flights.size() ;i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        queue<pair<int,pair<int,int>>> q;

        q.push({0,{src,0}});
        vector<int> distance(n,INT_MAX);

        while(!q.empty()){
            auto top = q.front();
            int stops = top.first;
            int currCity = top.second.first;
            int dist = top.second.second;

            q.pop(); 

            if( stops > k){
                continue;
            }

            for( auto neighbour : adj[currCity]){
                if( distance[neighbour.first] > dist + neighbour.second){
                    distance[neighbour.first] = dist + neighbour.second;
                    q.push({stops + 1,{neighbour.first,distance[neighbour.first]}});
                }
            }
        }
        if( distance[dst] == INT_MAX){
            return -1;
        }
        return distance[dst];
    }
};
