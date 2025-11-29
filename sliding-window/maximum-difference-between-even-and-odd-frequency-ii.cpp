class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        vector<vector<int>> prefix(5, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            if(i) for(int j = 0; j < 5; j++) prefix[j][i] = prefix[j][i-1];
            prefix[s[i] - '0'][i]++;
        }
        int res = INT_MIN;
        for(int i = 0; i < 5; i++){
            if(prefix[i][n-1] == 0) continue;
            for(int j = 0; j < 5; j++){
                if(i == j || prefix[j][n-1] == 0) continue;
                res = max(res, getMax(i, j, k, n, prefix));
            }
        }
        return res;
    }

    int getMax(int i, int j, int k, int n, vector<vector<int>>& prefix){
        int res = INT_MIN;
        const int INF=1e8;
        int minFreq[2][2]={{INF, INF},{INF, INF}};// 4 different of parity cases
        int freq_a=0, freq_b=0, prev_a=0, prev_b=0;
        for (int l=0, r=k-1; r < n; r++) {// use the advantage of of prefix sum r begins with k-1 instead of 0
            // freq[a], freq[b] at r, 1-indexed prefix sum
            freq_a=prefix[i][r], freq_b=prefix[j][r];
            // after shrinking, at least 1 b
            while( r-l+1>=k && freq_b-prev_b>=2){
                minFreq[prev_a&1][prev_b&1]=min(minFreq[prev_a&1][prev_b&1], prev_a-prev_b);// update freq[a]-freq[b] at l
                prev_a=prefix[i][l];// update prev freq, notice 1-indexed prefix sum
                prev_b=prefix[j][l];
                l++;// moving l
            }
            res = max(res, freq_a-freq_b-minFreq[1-(freq_a&1)][freq_b&1]);
        }
        return res;
    }
};