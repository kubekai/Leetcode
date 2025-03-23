class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 0; // 記錄操作次數
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // 若剩餘元素不足以翻轉（長度不足 3），則無法解決
                if (i + 2 >= n) {
                    return -1;
                }
                
                // 翻轉長度為 3 的子陣列
                for (int j = 0; j < 3; j++) {
                    nums[i + j] = 1 - nums[i + j]; // 0 -> 1, 1 -> 0
                }
                
                op++; // 計算操作次數
            }
        }
        
        return op;
    }
};
