class Solution {
public:
    bool isvaild(vector<vector<int>>& rectangles ,int sortIndex, int start, int end){
        sort(rectangles.begin(), rectangles.end(),
            [&](const vector<int>& a, const vector<int>& b) {
                return a[sortIndex] < b[sortIndex];
            });
        int currstart = rectangles[0][start];
        int currend = rectangles[0][end];
        int interval = 0;
        for(const auto& rect : rectangles){
            if(rect[start]<currend){
                currend = max(rect[end],currend);
            }
            else{
                interval++;
                currstart = rect[start];
                currend = rect[end];
            }
        }
        interval++;//計算間隔數量時，最後一個區間不會被 else 區塊計算到，因此需要額外補上
        return interval > 2;

    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        

        return isvaild(rectangles,0,0,2) || isvaild(rectangles,1,1,3);

    }
};
