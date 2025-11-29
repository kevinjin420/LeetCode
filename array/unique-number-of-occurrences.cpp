class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::set<int> lengths;
        int curr = arr[0];
        int curr_length = 0;;
        for(int n : arr){
            if(n != curr){
                if(lengths.contains(curr_length)){
                    return false;
                }
                lengths.insert(curr_length);
                curr = n;
                curr_length = 1;
            }
            else{
                curr_length++;
            }
        }
        if(lengths.contains(curr_length)){
            return false;
        }
        return true;
    }
};