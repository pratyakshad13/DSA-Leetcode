class Solution {
    int getAns(unordered_set<int> & stones,int steps,int currStone,int totalStones,map<pair<int,int>,bool> & dp){
        if( currStone == totalStones){
            return dp[{currStone,steps}] = 1;
        }
        if( currStone > totalStones){
            return 0;
        } 

        if(dp.count({currStone,steps}) > 0){
            return dp[{currStone,steps}];
        }  

        bool ans1 = false , ans2= false, ans3 = false;

        if(currStone + steps - 1 <= totalStones && steps != 1 && stones.count(currStone + steps - 1) == 1){
            ans1 = getAns(stones,steps - 1, currStone + steps - 1,totalStones,dp);
        }
        if(totalStones >= currStone + steps && stones.count(currStone + steps )== 1){
            ans2 = getAns(stones,steps, currStone + steps ,totalStones,dp);
        }
        if(totalStones >= currStone + steps + 1 && stones.count(currStone + steps + 1)== 1){
            ans3 = getAns(stones,steps + 1, currStone + steps + 1,totalStones,dp);
        }

        return dp[{currStone,steps}] = ans1 || ans2 || ans3;


    }
public:
    bool canCross(vector<int>& position) {
        
        int size = position.size();
        int totalStones = position[size - 1];
        
        unordered_set<int> stones;

        for( auto i : position){
            stones.insert(i);
        }
        if(stones.count(1) == 0){
            return false;
        }
        map<pair<int,int>,bool> dp;
        
        int steps = 1;
        int currStone = 1;
        return getAns(stones,steps,currStone,totalStones,dp);
        
    }
};
