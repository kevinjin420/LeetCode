class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (!hasZeroDigit(a) && !hasZeroDigit(b)) {
                return {a, b};
            }
        }
        return {-1};
    }

private:
    bool hasZeroDigit(int x) {
        while (x > 0) {
            if (x % 10 == 0) return true;
            x /= 10;
        }
        return false;
    }
};
