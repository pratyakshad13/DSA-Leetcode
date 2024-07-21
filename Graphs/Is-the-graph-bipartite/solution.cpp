class Solution {
private:
    bool isBipartite(int node,vector<vector<int>>& graph,vector<int>& color,int colorOfNode){
        color[node] = colorOfNode;
        //cout<<"We are at "<<node<<" node"<<endl;
        bool ans = true;
        for( auto neighbour : graph[node]){
            if( color[neighbour] == -1 ){
                color[neighbour] = !colorOfNode;
                ans = isBipartite(neighbour,graph,color,!colorOfNode);
                // if(!ans){
                //     return false;
                // }
            }
            else if( color[neighbour] == colorOfNode){
                return false;
            }
        }

        return ans;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> color(size,-1);
        

        for( int i = 0; i < size; i++){
            if(color[i] == -1){
                bool  ans = isBipartite(i,graph,color,0);
                if(!ans){
                    return false;
                }
            }
        }
        return true;
    }
};
