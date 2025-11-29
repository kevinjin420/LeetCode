class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& lhs, const vector<int>& rhs){return lhs[0] < rhs[0];});
        vector<int> rooms(n, 0);
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> ends;
        for(int i = 0; i < n; i++) free.push(i);

        for(vector<int> meeting : meetings){
            long long start = meeting[0], end = meeting[1];
            while(ends.size() && ends.top().first <= start){
                free.push(ends.top().second);
                ends.pop();
            }
            int cur_room;
            if(free.size()){
                cur_room = free.top();
                free.pop();
                ends.push({end, cur_room});
            }
            else{
                cur_room = ends.top().second;
                long long cur_start = ends.top().first;
                ends.pop();
                ends.push({end - start + max(cur_start, start), cur_room});
            }
            rooms[cur_room]++;
        }

        return max_element(rooms.begin(), rooms.end()) - rooms.begin();
    }
};