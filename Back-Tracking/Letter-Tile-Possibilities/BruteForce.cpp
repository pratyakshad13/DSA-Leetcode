class Solution {
    void getAllPossibilities(string& tiles,vector<string> & ans,int pos,string temp){
        if( pos>= tiles.size()){
            ans.push_back(temp);
            return;
        }
        temp+=tiles[pos];
        getAllPossibilities(tiles,ans,pos+1,temp);
        temp.pop_back();
        getAllPossibilities(tiles,ans,pos+1,temp);
    }
    void getAnswer(set<string> & st,string & s,int pos){
        if(pos >= s.size()){
            st.insert(s);
            return;
        }

        for( int i = pos ;i <s.size() ; i++){
            swap(pos,i,s);
            getAnswer(st,s,pos+1);
            swap(pos,i,s);
        }
    }
    void swap(int i ,int j ,string & s){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<string> ans;
        getAllPossibilities(tiles,ans,0,"");

        // for(auto st : ans){
        //     cout<< st<<endl;
        // }
        set<string> st;


        for( auto element : ans){
            getAnswer(st,element,0);
        }
        return st.size() - 1;

    }
};


