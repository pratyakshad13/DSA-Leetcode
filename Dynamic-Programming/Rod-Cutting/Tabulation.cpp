  int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n + 1,0));
        
        for( int currLength = 0 ; currLength <= n ; currLength++){
            dp[0][currLength] = currLength * price[0];
        }
        
        for(int index = 1 ; index < n ; index++){
            for( int currLength = 0 ; currLength <= n ;currLength++){
                int takeThis = INT_MIN;
                int dontTakeThis = dp[index - 1][currLength];
                if( currLength >= index + 1 ){
                    takeThis = dp[index][currLength - (index + 1)] + price[index];
                }
                dp[index][currLength] = max(takeThis,dontTakeThis);
            }
            
        }
        
        return dp[n - 1][n];
    }
