class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int last = 0, n = startTime.size();
        int maxLeft = 0, res = 0;
        vector<int> gaps(n+1, 0);
        for(int i = 0; i < n; i++){
            gaps[i] = startTime[i] - last;
            last = endTime[i];
        }
        gaps[n] = eventTime - last;

        vector<int> maxGap(n+1, 0);
        for(int i = n-1; i >= 0; i--) maxGap[i] = max(maxGap[i+1], gaps[i+1]);

        for(int i = 1; i <= n; i++){
            int curr = endTime[i-1] - startTime[i-1];
            if(curr <= maxGap[i] || curr <= maxLeft) res = max(res, gaps[i-1] + curr + gaps[i]);
            res = max(res, gaps[i-1] + gaps[i]);
            maxLeft = max(maxLeft, gaps[i-1]);
        }

        return res;
    }
};