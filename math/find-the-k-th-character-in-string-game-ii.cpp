class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int sum = 0;
        int i = 0;
        k--;
        while(k != 0){
            sum += ((k & 1) & operations[i]);
            i++;
            k >>= 1;
        }
        return 'a' + (sum % 26);
    }
};