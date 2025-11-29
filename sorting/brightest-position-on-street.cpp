class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        int n = lights.size();
        vector<int> starts; starts.reserve(n);
        vector<int> ends; ends.reserve(n);
        for(auto& entry : lights){
            starts.push_back(entry.front() - entry.back());
            ends.push_back(entry.front() + entry.back() + 1);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int s = 0, e = 0;
        int brightest = 0, res = 0;
        int curr = 0;
        while(s < n){
            if (starts[s] < ends[e]){
                curr++;
                if(curr > brightest){
                    brightest = curr;
                    res = starts[s];
                }
                s++;
            }
            else {
                curr--;
                e++;
            }
        }
        return res;
    }
};