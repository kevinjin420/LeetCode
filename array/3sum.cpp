class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int target = 0;
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            while(i > 0 && i < arr.size() && arr[i] == arr[i-1]) i++;
            if(i == arr.size()) continue;
            int missing = target - arr[i];
            int l = i + 1, r = arr.size() - 1;
            while(l < r){
                if(arr[l] + arr[r] < missing) l++;
                else if(arr[l] + arr[r] > missing) r--;
                else{
                    res.push_back({arr[i], arr[l], arr[r]});
                    l++;
                    while(arr[l] == arr[l-1] && l < r) l++;
                }
            }
        }
        return res;
    }
};