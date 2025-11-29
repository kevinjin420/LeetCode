class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int day = 0, index = 0, n = events.size(), count = 0;
        while(pq.size() || index < n){
            if(pq.empty()) day = events[index][0];
            while(index < n && events[index][0] <= day){
                pq.push(events[index][1]); index++;
            }
            pq.pop();
            count++;
            day++;
            while(pq.size() && pq.top() < day) pq.pop();
        }
        return count;
    }
};