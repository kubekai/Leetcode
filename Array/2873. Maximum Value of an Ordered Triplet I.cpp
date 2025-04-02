class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        long long result = 0;
        long long max_diff = 0;
        long long max_i = 0;\

        for(long long num : nums){
            result = max(result,max_diff * num);
            max_diff = max(max_diff,max_i - num);
            max_i = max(max_i,num);

        }
        return result;
    }
};
