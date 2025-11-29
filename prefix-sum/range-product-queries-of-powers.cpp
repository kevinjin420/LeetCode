
class Solution {
public:
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        long long current_base = base % mod;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * current_base) % mod;
            }
            current_base = (current_base * current_base) % mod;
            exp >>= 1;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1000000007;

        vector<int> powers;
        for (int bit = 0; bit < 31; ++bit) {
            if ((n & (1 << bit)) != 0) {
                powers.push_back(bit);
            }
        }

        vector<long long> prefix_sums(powers.size() + 1, 0);
        for (size_t i = 0; i < powers.size(); ++i) {
            prefix_sums[i + 1] = prefix_sums[i] + powers[i];
        }

        vector<int> results;
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];

            long long exponent_sum = prefix_sums[right + 1] - prefix_sums[left];
            int product_mod = (int)modPow(2, exponent_sum, MOD);
            results.push_back(product_mod);
        }

        return results;
    }
};