class Solution {
private:
    bool checkCycle(int node,vector<vector<int>>& prerequisites,vector<pair<int,int>>& pathVisited){
        pathVisited[node].first=1;
        pathVisited[node].second=1;

        for(auto neighbour:prerequisites[node]){
            if(!pathVisited[neighbour].first){
                pathVisited[neighbour].first=1;
                bool ans1=checkCycle(neighbour,prerequisites,pathVisited);
                if(ans1){
                    return true;
                }
            }else{
                if(pathVisited[neighbour].second==1){
                    return true;
                }
            }
        }
        pathVisited[node].second=0;
        return false;
    }
    void topoOrder(int node,vector<vector<int>>& prerequisites,stack<int>& s,vector<int> & isVisited){
        isVisited[node]=1;
        for(auto i:prerequisites[node]){
            if(!isVisited[i]){
                isVisited[i]=1;
                topoOrder(i,prerequisites,s,isVisited);
            }
        }
        s.push(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& grid) {
        vector<vector<int>> prerequisites;
        for(int i=0;i<numCourses;i++){
            prerequisites.push_back({});
        }
        for(int i=0;i<grid.size();i++){
            int u=grid[i][0];
            int v=grid[i][1];
            prerequisites[v].push_back(u);
        }
        
        vector<pair<int,int>> isVisitedPath;
        for(int i=0;i<numCourses;i++){
            isVisitedPath.push_back({0,0});
        }
        for(int i=0;i<numCourses;i++){
            if(!isVisitedPath[i].first){
                bool ans1=checkCycle(i,prerequisites,isVisitedPath);
                if(ans1){
                    cout<<"Cycle is present";
                    return {};
                }
            }
        }
        stack<int> tempStack;
        vector<int> ans;
        vector<int> isVisited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!isVisited[i]){
                topoOrder(i,prerequisites,tempStack,isVisited);
            }
        }
        while(!tempStack.empty()){
            ans.push_back(tempStack.top());
            tempStack.pop();
        }
        return ans;
        

    }
};
