class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> arr;

        arr.push_back(meetings[0]);
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0] <= arr.back()[1]){ //重疊
                arr.back()[1] = max(arr.back()[1],meetings[i][1]);
            }
            else{
                arr.push_back(meetings[i]);
            }
        }
        int meet_count = 0;
        for(int i=0;i<arr.size();i++){
            meet_count += (arr[i][1] - arr[i][0] + 1);
        }
        return days - meet_count;
        
    }
};
