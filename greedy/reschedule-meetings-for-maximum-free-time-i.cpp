class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gap(n + 1);
        gap[0] = startTime[0]; gap[n] = eventTime - endTime[n-1];
        for(int i = 1; i < n; i++) gap[i] = startTime[i] - endTime[i-1];
        int l = 0, r = k;
        int res = 0, sum = 0;
        for(int i = 0; i <= min(k, n); i++) sum += gap[i];
        res = max(res, sum);
        while(r < n){
            sum -= gap[l++];
            sum += gap[++r];
            res = max(res, sum);
        }
        return res;
    }
};