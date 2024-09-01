class Solution {
private:
    void getTheKthPermutation(vector<int> & visited,vector<int> & ans,vector<int> &temp,int n,int k,int & counter){
        if( accumulate(visited.begin(),visited.end(),0) == n){
            counter++;
            if( k == counter){
                ans = temp;
            }
            return;
        }

        for( int i = 1 ; i <= n ; i++){
           if( visited[i] != 1){
            visited[i] = 1;
            temp.push_back(i);
            getTheKthPermutation(visited,ans,temp,n,k,counter);
            temp.pop_back();
            visited[i] = 0;
           }
        }
    }
public:
    string getPermutation(int n, int k) {
        vector<int> visited(n+1,0);
        int counter = 0;
        vector<int> ans;
        vector<int> temp;
        getTheKthPermutation(visited,ans,temp,n,k,counter);
        string res="";
        for( auto i : ans){
            res += to_string(i);
        }
        return res;
    }
};
