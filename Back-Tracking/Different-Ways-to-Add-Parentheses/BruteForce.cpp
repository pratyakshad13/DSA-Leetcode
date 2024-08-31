class Solution {
private:
    vector<int> getAllPossibleAnswer(int start ,int end,string &s){
        int length = end - start + 1;
        if( length <= 2){
            return  {stoi(s.substr(start,length))};
        }

        vector<int> possibleAns;

        for( int i = start ; i <= end ; i++){
            if( s[i] =='+' || s[i] =='-' || s[i] =='*' ){
                vector<int> allLeftPossibleAnswers = getAllPossibleAnswer(start,i - 1,s);
                vector<int>allrightPossibleAnswers = getAllPossibleAnswer(i + 1,end ,s);

                for( auto x : allLeftPossibleAnswers){
                    for( auto y : allrightPossibleAnswers){
                        if(s[i] == '+'){
                            possibleAns.push_back(x + y);
                        }
                        else if(s[i] == '-'){
                            possibleAns.push_back(x - y);
                        }
                        else{
                            possibleAns.push_back(x * y);
                        }
                    }
                }
            }
        }
        return possibleAns;

        
    }
public:
    vector<int> diffWaysToCompute(string s) {
        
        return getAllPossibleAnswer(0,s.size() - 1,s);
    }
};
