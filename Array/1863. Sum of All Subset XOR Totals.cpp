class Solution {
public:
    void getXORsum(vector<int>& nums,int index,int currxor,int &total){
        if(index == nums.size()){ //如果到最後一個的下一個，就加目前的結果
            total += currxor;
            return;
        }
        getXORsum(nums,index+1,currxor ^nums[index],total);
        getXORsum(nums,index+1,currxor,total);

    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        getXORsum(nums,0,0,sum);
        return sum;
    }
};
