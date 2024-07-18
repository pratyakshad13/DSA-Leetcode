// solved using disjoint set

class DisjointSet{
    public:
    vector<int> parent,rank,size;
    DisjointSet(int n){
        rank.resize(n,0);
        size.resize(n,1);
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
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);

        if( rank[ultimateParentU] > rank[ultimateParentV]){
            parent[ultimateParentV] = ultimateParentU;
            rank[ultimateParentU]++;
        }
        else{
            parent[ultimateParentU] = ultimateParentV;
            rank[ultimateParentV]++;
        }
    }

    void unionBySize(int u , int v){
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);

        if(size[ultimateParentU] > size[ultimateParentV]){
            ultimateParentV = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
        else{
            ultimateParentU = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        }
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int countOfExtraCables = 0;
        int countOfDisconnectedComputer = 0;

        DisjointSet ds(n);

        sort(connections.begin(),connections.end());

        for( int i = 0 ; i < connections.size() ; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                ds.unionByRank(u,v);
            }
            else if(ds.findUltimateParent(u) == ds.findUltimateParent(v)){
                countOfExtraCables++;
            }
        }
        for( int i = 0 ; i < n ; i++){
            if( ds.findUltimateParent(i) == i){
                countOfDisconnectedComputer++;
            }
        }

        if(countOfDisconnectedComputer - 1 <= countOfExtraCables ){
            return countOfDisconnectedComputer - 1;
        }

        return -1;

    }
};
