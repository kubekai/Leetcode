class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int rem = temp[0]%x;
        int op = 0;
        int med = temp.size()/2;
        for(int i=0;i<temp.size();i++){
            if(temp[i]%x != rem){
                return -1;
            }
            else{
                op += abs(temp[i] - temp[med]) / x;
            }
        }
        return op;
        

    }
};
