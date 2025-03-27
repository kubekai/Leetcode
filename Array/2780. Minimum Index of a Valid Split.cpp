class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> freq;
        int dom = 0;
        int dom_count = 0;
        vector<int> max_num;
        for(const auto& n : nums) {
            freq[n] += 1;
        }
        for (auto& [num, c] : freq) {
            if (c > nums.size() / 2) { // 確保它出現超過 nums.size()/2
                dom = num;
                dom_count = c;
                break;
            }
        }
        int leftcount = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == dom){
                leftcount++;
            }

            int leftsize = i+1;
            int rightsize = nums.size() - leftsize;
            int rightcount = dom_count - leftcount;

            if((2*leftcount > leftsize)&&(2*rightcount > rightsize)){
                return i;
            }
        }
        return -1;
    }
};
