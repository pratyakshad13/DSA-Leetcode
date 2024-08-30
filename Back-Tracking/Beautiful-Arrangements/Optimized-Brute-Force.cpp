//Here instead of generating all permutaions we will generate those where any one of the above 2 given conditions satisfy.



class Solution {
private:
    void swap( vector<int> & perms, int i ,int  j ){
        int temp = perms[i];
        perms[i] = perms[j];
        perms[j] = temp;
    }
    void getCount(vector<int> & perms,vector<vector<int>> & ans,int pos,int n,int &count){
        if(pos >= perms.size()){
            count++;
            return;
        }

        for( int i = pos ; i <perms.size() ; i++){
            swap(perms,pos, i );
            if((perms[pos])%(pos+1) == 0 || (pos + 1)%perms[pos] ==0)
                getCount(perms,ans,pos+1,n,count);
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
        int count = 0;
        getCount(perms,ans,0,n,count);
        
        return count;

    }
};
