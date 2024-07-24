## Using Disjoint Set

class DisjointSet{
    public:
    vector<int> parent,size,rank;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for( int i = 0 ; i < n ; i++){
            parent.push_back(i);
        }
    }

    int findUltimateParent(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionByRank(int u , int v){
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if( rank[parentU] == rank[parentV]){
            parent[parentV] = parentU;
            rank[parentU]++;
        }
        else{
            parent[parentU] = parentV;
            rank[parentV]++;
        }
    }

    void unionBySize(int u , int v){
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if( size[parentU] == size[parentV]){
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        else{
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }
};



class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n + 1);
        for( int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i != j && isConnected[i][j] == 1 && ds.findUltimateParent(i+1) != ds.findUltimateParent(j+1)){
                    ds.unionBySize(i + 1, j + 1);
                }
            }
        }

        int count = 0 ;

        for( int i = 1 ; i < n + 1; i++){
            if(ds.findUltimateParent(i) == i){
                count++;
            }
        }
        return count ;
    }
};
