class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        if(totalsum % 2 != 0) return false;
        int target = totalsum/2;

        vector<int> dp(target+1,false);
        dp[0] = true; //目標是零的時候一定能達成

        for(int num:nums){
            for(int j=target;j>=num;j--){
                dp[j] = dp[j] | dp[j-num];
            }
        }
        return dp[target];

    }
};
