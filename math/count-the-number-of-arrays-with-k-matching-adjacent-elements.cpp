class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long a, long long mod) {
        return modPow(a, mod - 2, mod);
    }

    long long nChooseK(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n / 2) k = n - k;

        long long num = 1, den = 1;
        for (int i = 0; i < k; ++i) {
            num = (num * (n - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        return (num * modInverse(den, MOD)) % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        if (k > n - 1) return 0;
        long long part1 = m % MOD;
        long long part2 = modPow(m - 1, n - k - 1, MOD);
        long long part3 = nChooseK(n - 1, k);
        return (((part1 * part2) % MOD) * part3) % MOD;
    }
};