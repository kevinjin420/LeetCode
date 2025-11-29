class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        while(res.size() < k){
            int n = res.size();
            for(int i = 0; i < n; i++){
                res += res[i] + 1;
            }
        }
        return res[k-1];
    }
};