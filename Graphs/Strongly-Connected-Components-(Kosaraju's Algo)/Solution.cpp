{
    
    
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<vector<int>>& adj,vector<int> & visited,stack<int> & st,int node){
	    visited[node] = 1;
	    
	    for( auto neighbour : adj[node]){
	        if(!visited[neighbour]){
	            dfs(adj,visited,st,neighbour);
	        }
	    }
	    st.push(node);
	    
	}
	
	void dfsNew(vector<int> adj[],vector<int> & visited,int node){
	    visited[node] = 1;
	    
	    for( auto neighbour : adj[node]){
	        if(!visited[neighbour]){
	            dfsNew(adj,visited,neighbour);
	        }
	    }
	    
	}
	
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visited(V,0);
        stack<int> st;
        for( int i = 0 ; i < V ; i++){
            if( !visited[i]){
                dfs(adj,visited,st,i);
            }
        }
        
        vector<int> newAdj[V];
        // for( int i = 0 ; i < V ; i++){
        //     newAdj.push_back({});
        // }
        
        for( int i = 0 ; i < V ; i++){
            for( auto ele : adj[i]){
                newAdj[ele].push_back(i);
            }
        }
        
        for( int i = 0 ; i < V ; i++){
            visited[i] = 0;
        }
        int count = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            if(!visited[top]){
                count++;
                dfsNew(newAdj,visited,top);
            }
        }
        return count;
        
    }
};
