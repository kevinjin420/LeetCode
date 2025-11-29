class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> starts;
        vector<int> ends;
        starts.reserve(n);
        ends.reserve(n);
        for(auto& i : intervals){
            starts.push_back(i.front());
            ends.push_back(i.back());
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int s = 0, e = 0;
        int curr = 0, res = 0;

        while (s < n) {
            if (starts[s] < ends[e]) {
                curr++;
                res = max(res, curr);
                s++;
            } else {
                curr--;
                e++;
            }
        }

        return res;
    }
};