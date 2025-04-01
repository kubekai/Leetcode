class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int next = questions[i][1] + i + 1;
            long long take = questions[i][0];
            if (next < n){
                take += dp[next];
            }
            long long skip = dp[i+1];
            dp[i] = max(skip,take);
        }
        
        return dp[0];
    }
};
