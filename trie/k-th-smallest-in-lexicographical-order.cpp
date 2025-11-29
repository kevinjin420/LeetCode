class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1; k--;
        while(k > 0){
            int size = getBranchSize(n, curr, curr + 1);
            if(size > k){
                curr *= 10;
                k--;
            }
            else{
                curr++;
                k -= size;
            }
        }
        return curr;
    }
    
    long getBranchSize(long n, long curr, long next){
        if(curr > n) return 0;
        return min(n + 1, next) - curr + getBranchSize(n, curr * 10, next * 10);
    }
};