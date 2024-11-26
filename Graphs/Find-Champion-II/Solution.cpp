/*Intuition:

Count the indegree of all the nodes. If there is any node whode indegree is 0, that simply implies, that particular node is the strongest team as no other team is stronger
( mentioned in the Problem statement). 
And if tere are multiple nodes with indegree 0, Retrun -1.
*/

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n,0);

        for(auto node : edges){
            inDegree[node[1]]++;
        }
        
        int nodeFound = false;
        int nodeNumber = INT_MIN;

        for( int i = 0 ; i < inDegree.size() ; i++){
            if(inDegree[i] == 0 ){
                if( !nodeFound ){
                    nodeNumber = i;
                    nodeFound = 1;
                }
                else{
                    return -1;
                }
            } 
        }
        return nodeNumber;
    }

};
