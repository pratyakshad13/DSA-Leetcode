class Solution {
private:
    void swap( vector<int> & perms, int i ,int  j ){
        int temp = perms[i];
        perms[i] = perms[j];
        perms[j] = temp;
    }
    void getAllPermuatations(vector<int> & perms,vector<vector<int>> & ans,int pos,int n){
        if(pos >= perms.size()){
            ans.push_back(perms);
            return;
        }

        for( int i = pos ; i <perms.size() ; i++){
            swap(perms,pos, i );
            getAllPermutations(perms,ans,pos+1,n);
            swap(perms,pos,i);
        }
    }
public:
    int countArrangement(int n) {
        vector<int> perms;
        for( int i = 1 ; i <= n ; i++){
            perms.push_back(i);
        }
        vector<vector<int>> ans;
        getAllPermutations(perms,ans,0,n);
        

        int count = 0;

        for( auto ele : ans){
            int i ;
            for(  i = 0 ; i < ele.size() ; i++){
                
                if((ele[i])%(i+1) != 0 && (i + 1)%ele[i] !=0 ){
                    break;
                }
            }
            if(i == ele.size()){
                count++;
            }
        }
        return count;

    }
};
