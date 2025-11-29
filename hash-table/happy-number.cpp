class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1){
            int num = n;
            int sum = 0;
            while(num){
                sum += pow((num % 10), 2);
                num /= 10;
            }
            n = sum;
            if(seen.find(n) != seen.end()) return false;
            else seen.insert(n);
        }
        return true;
    }
};