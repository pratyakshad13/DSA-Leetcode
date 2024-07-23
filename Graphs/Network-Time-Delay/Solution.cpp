class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n+1];
        for( int i = 0 ; i < times.size() ; i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
            // adj[times[i][1]].push_back({times[i][0],times[i][2]});
        }
        vector<int> timeVisited(n+1,INT_MAX);
        timeVisited[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        int ans = INT_MIN;

        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();

            int time = top.first;
            int node = top.second;

            for(auto neighbour : adj[node]){
                int currNode = neighbour[0];
                int timeRequired = neighbour[1];
                if(timeVisited[currNode] > time + timeRequired){
                    timeVisited[currNode] = time + timeRequired;
                    // ans = max(ans,timeVisited[currNode]);
                    pq.push({timeVisited[currNode],currNode});
                }
            }
        }
        // 
        for( int i = 1 ; i < timeVisited.size() ; i++){
            if(timeVisited[i] == INT_MAX){
                return - 1;
            }
            ans = max(ans,timeVisited[i]);
        }
        return ans;
    }
};
